/*
 * usb-config.h
 *
 *  Created on: Oct 20, 2017
 *      Author: technix
 */

#ifndef INCLUDE_USB_CONFIG_H_
#define INCLUDE_USB_CONFIG_H_

#define USB_VID              0x0002  // Obsolete VID of Ingram. Unlikely to clash.
#define USB_PID              0xC001

#define USB_MANUFACTURER     "SushiBits by Max Chan <xcvista@me.com>"
#define USB_PRODUCT          "USB Light Switch"

#define USB_RXD_EP	0x01
#define USB_TXD_EP	0x82
#define USB_PKT_SZ	64

__attribute__((packed)) struct config_descriptor
{
	struct usb_config_descriptor	 config;
	struct usb_interface_descriptor interface;
	struct usb_hid_descriptor hid_descriptor;
	struct usb_endpoint_descriptor endpoints[2];
};

static const struct usb_device_descriptor device_descriptor =
{
	    .bLength            = sizeof(struct usb_device_descriptor),
	    .bDescriptorType    = USB_DTYPE_DEVICE,
	    .bcdUSB             = VERSION_BCD(2, 0, 0),
	    .bDeviceClass       = USB_CLASS_PER_INTERFACE,
	    .bDeviceSubClass    = USB_SUBCLASS_NONE,
	    .bDeviceProtocol    = USB_PROTO_NONE,
	    .bMaxPacketSize0    = USB_PKT_SZ,
	    .idVendor           = USB_VID,
	    .idProduct          = USB_PID,
	    .bcdDevice          = VERSION_BCD(0, 1, 0),
	    .iManufacturer      = 1,
	    .iProduct           = 2,
	    .iSerialNumber      = INTSERIALNO_DESCRIPTOR,
	    .bNumConfigurations = 1
};

static const struct usb_qualifier_descriptor qualifier_descriptor =
{
	    .bLength            = sizeof(struct usb_qualifier_descriptor),
	    .bDescriptorType    = USB_DTYPE_QUALIFIER,
	    .bcdUSB             = VERSION_BCD(2, 0, 0),
	    .bDeviceClass       = USB_CLASS_HID,
	    .bDeviceSubClass    = USB_SUBCLASS_NONE,
	    .bDeviceProtocol    = USB_PROTO_NONE,
	    .bMaxPacketSize0    = USB_PKT_SZ,
	    .bNumConfigurations = 1,
	    .bReserved          = 0
};

static const uint8_t usb_hid_report[] =
{
	    0x06, 0x00, 0xff,              // USAGE_PAGE (Vendor Defined Page 1)
	    0x09, 0x01,                    // USAGE (Vendor Usage 1)
	    0xa1, 0x01,                    // COLLECTION (Application)
	    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
	    0x27, 0xff, 0xff, 0x00, 0x00,  //   LOGICAL_MAXIMUM (65535)
	    0x75, 0x10,                    //   REPORT_SIZE (16)
	    0x95, 0x01,                    //   REPORT_COUNT (1)
	    0x09, 0x01,                    //   USAGE (Vendor Usage 1)
	    0x81, 0x82,                    //   INPUT (Data,Var,Abs,Vol)
	    0x95, 0x01,                    //   REPORT_COUNT (1)
	    0x09, 0x01,                    //   USAGE (Vendor Usage 1)
	    0x91, 0x82,                    //   OUTPUT (Data,Var,Abs,Vol)
	    0xc0                           // END_COLLECTION
};

#define USB_REPORT	sizeof(usb_hid_report)

static const struct config_descriptor config_descriptor =
{
		.config =
		{
		        .bLength                = sizeof(struct usb_config_descriptor),
		        .bDescriptorType        = USB_DTYPE_CONFIGURATION,
		        .wTotalLength           = sizeof(config_descriptor),
		        .bNumInterfaces         = 1,
		        .bConfigurationValue    = 1,
		        .iConfiguration         = NO_DESCRIPTOR,
		        .bmAttributes           = USB_CFG_ATTR_RESERVED,
		        .bMaxPower              = USB_CFG_POWER_MA(300)
		},
		.interface =
		{
		        .bLength                = sizeof(struct usb_interface_descriptor),
		        .bDescriptorType        = USB_DTYPE_INTERFACE,
		        .bInterfaceNumber       = 0,
		        .bAlternateSetting      = 0,
		        .bNumEndpoints          = 2,
		        .bInterfaceClass        = USB_CLASS_HID,
		        .bInterfaceSubClass     = USB_SUBCLASS_NONE,
		        .bInterfaceProtocol     = USB_PROTO_NONE,
		        .iInterface             = NO_DESCRIPTOR,
		},
		.hid_descriptor =
		{
				.bLength                = sizeof(struct usb_hid_descriptor),
				.bDescriptorType        = USB_DTYPE_HID,
				.bcdHID                 = VERSION_BCD(1, 1, 1),
				.bCountryCode           = USB_HID_COUNTRY_US,
				.bNumDescriptors        = 1,
				.bDescriptorType0       = USB_DTYPE_HID_REPORT,
				.wDescriptorLength0     = USB_REPORT
		},
		.endpoints =
		{
				{
				        .bLength                = sizeof(struct usb_endpoint_descriptor),
				        .bDescriptorType        = USB_DTYPE_ENDPOINT,
				        .bEndpointAddress       = USB_RXD_EP,
				        .bmAttributes           = USB_EPTYPE_INTERRUPT,
				        .wMaxPacketSize         = USB_PKT_SZ,
				        .bInterval              = 100,
				},
				{
				        .bLength                = sizeof(struct usb_endpoint_descriptor),
				        .bDescriptorType        = USB_DTYPE_ENDPOINT,
				        .bEndpointAddress       = USB_TXD_EP,
				        .bmAttributes           = USB_EPTYPE_INTERRUPT,
				        .wMaxPacketSize         = USB_PKT_SZ,
				        .bInterval              = 100,
				}
		}
};

static const struct usb_string_descriptor lang_desc     = USB_ARRAY_DESC(USB_LANGID_ENG_US);
static const struct usb_string_descriptor manuf_desc_en = USB_STRING_DESC(USB_MANUFACTURER);
static const struct usb_string_descriptor prod_desc_en  = USB_STRING_DESC(USB_PRODUCT);
static const struct usb_string_descriptor *const desc_string_table[] =
{
		&lang_desc,
		&manuf_desc_en,
		&prod_desc_en,
};

#endif /* INCLUDE_USB_CONFIG_H_ */
