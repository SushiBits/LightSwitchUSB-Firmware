/*
 * usb-device.c
 *
 *  Created on: Oct 20, 2017
 *      Author: technix
 */

#include <stm32f0xx.h>
#include <stm32f0xx_it.h>
#include <stdalign.h>
#include <stddef.h>
#include <usb.h>
#include <usb_hid.h>
#include <time.h>
#include <stdbool.h>

#include "usb-config.h"
#include "usb-device.h"
#include "led.h"

static usbd_device usb_device;
static uint32_t usb_buffer[USB_PKT_SZ];

static usbd_respond usb_get_descriptor(usbd_ctlreq *req, void **address, uint16_t *length);
static usbd_respond usb_control(usbd_device *dev, usbd_ctlreq *req, usbd_rqc_callback *callback);
static usbd_respond usb_set_config(usbd_device *dev, uint8_t cfg);
static void usb_handle(usbd_device *dev, uint8_t event, uint8_t ep);
clock_t last_poll = 0;

__attribute__((constructor)) void usb_init(void)
{
	usbd_init(&usb_device, &usbd_hw, USB_PKT_SZ, usb_buffer, sizeof(usb_buffer));
	usbd_reg_descr(&usb_device, usb_get_descriptor);
	usbd_reg_control(&usb_device, usb_control);
	usbd_reg_config(&usb_device, usb_set_config);

	usbd_enable(&usb_device, true);
	usbd_connect(&usb_device, true);
	USB->BCDR |= USB_BCDR_DPPU;

	NVIC_EnableIRQ(USB_IRQn);
}

void USB_IRQHandler(void)
{
	usbd_poll(&usb_device);
}

static usbd_respond usb_get_descriptor(usbd_ctlreq *req, void **address, uint16_t *length)
{
	uint8_t descriptor_type = (req->wValue & 0xff00) >> 8;
	uint8_t descriptor_idx = req->wValue & 0xff;

	const void *buf = NULL;
	uint16_t len = 0;

	switch (descriptor_type)
	{
	case USB_DTYPE_DEVICE:
		buf = &device_descriptor;
		break;

	case USB_DTYPE_CONFIGURATION:
		buf = &config_descriptor;
		len = sizeof(config_descriptor);
		break;

	case USB_DTYPE_QUALIFIER:
		buf = &qualifier_descriptor;
		break;

	case USB_DTYPE_HID:
		buf = &config_descriptor.hid_descriptor;
		break;

	case USB_DTYPE_HID_REPORT:
		buf = usb_hid_report;
		len = USB_REPORT;
		break;

	case USB_DTYPE_STRING:
		if (descriptor_idx < sizeof(desc_string_table) / sizeof(struct usb_string_descriptor))
			buf = desc_string_table[descriptor_idx];
		break;

	default:
		break;
	}

	if (!buf)
		return usbd_fail;
	len = len ?: ((struct usb_device_descriptor *)buf)->bLength;

	if (address)
		*address = (void *)buf;
	if (length)
		*length = len;

	return usbd_ack;
}

static usbd_respond usb_control(usbd_device *dev, usbd_ctlreq *req, usbd_rqc_callback *callback)
{
	usbd_respond result = usbd_fail;

	if (req->bRequest == USB_STD_GET_DESCRIPTOR)
		return usb_get_descriptor(req, &dev->status.data_ptr, &dev->status.data_count);

	return result;
}

static usbd_respond usb_set_config(usbd_device *dev, uint8_t cfg)
{
	switch (cfg)
	{
	case 0:
		// Deconfigure everything.
		usbd_ep_deconfig(&usb_device, USB_RXD_EP);
		usbd_ep_deconfig(&usb_device, USB_TXD_EP);
		usbd_reg_endpoint(&usb_device, USB_RXD_EP, NULL);
		usbd_reg_endpoint(&usb_device, USB_TXD_EP, NULL);
		return usbd_ack;

	case 1:
		usbd_ep_config(dev, USB_RXD_EP, USB_EPTYPE_INTERRUPT, USB_PKT_SZ);
		usbd_ep_config(dev, USB_TXD_EP, USB_EPTYPE_INTERRUPT, USB_PKT_SZ);
		usbd_reg_endpoint(dev, USB_RXD_EP, usb_handle);
		usbd_reg_endpoint(dev, USB_TXD_EP, usb_handle);
		usbd_ep_write(dev, USB_TXD_EP, NULL, 0);
        return usbd_ack;

	default:
		break;
	}
	return usbd_fail;
}

static void usb_handle(usbd_device *dev, uint8_t event, uint8_t ep)
{
	bool update_poll = false;
	switch (event)
	{
	case usbd_evt_eptx:
		usbd_ep_write(dev, USB_TXD_EP, &brightness, sizeof(brightness));
		update_poll = true;
		break;

	case usbd_evt_eprx:
		usbd_ep_read(dev, USB_RXD_EP, &brightness, sizeof(brightness));
		update_poll = true;
		break;

	default:
		break;
	}

	if (update_poll)
	{
		last_poll = clock();
	}
}
