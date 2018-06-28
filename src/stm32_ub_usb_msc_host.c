//--------------------------------------------------------------
// File     : stm32_ub_usb_msc_host.c
// Datum    : 10.04.2013
// Version  : 1.0
// Autor    : UB
// EMail    : mc-4u(@)t-online.de
// Web      : www.mikrocontroller-4u.de
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.0
// Module   : GPIO, MISC, STM32_UB_FATFS
// Funktion : USB-MSC-HOST per USB-OTG-Port am Discovery
//
//            ������ ���������� ������ ������� USB-HOST
//            ��� ���������� ������� ������������ ����������
//            "stm32_ub_fatfs" (USB-������)
//
// ������   : ��������� ����-���������� USB �� ��������������
//            � ������ ���� ������ Intenso 4GB, ������� ��������
//            Sandisk 8GB �� �������� !!
//
//            ������ Discovery �������� ������ � ������
//            USB-FullSpeed-Mode (USB-High-Speed �� ��������)

//--------------------------------------------------------------
//              PA9   -> USB_OTG_VBUS
//              PA10  -> USB_OTG_ID
//              PA11  -> USB_OTG_DM
//              PA12  -> USB_OTG_DP
//              PC0   -> USB_VBUS_Enable
//--------------------------------------------------------------


//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32_ub_usb_msc_host.h"



//--------------------------------------------------------------
// ���������� ����������
//--------------------------------------------------------------
USB_OTG_CORE_HANDLE          USB_OTG_Core;
USBH_HOST                    USB_Host;




//--------------------------------------------------------------
// ������������� USB OTG ����, ��� MSC-Host
// (Host ������ ��� ������� ���������, ����� ��� USB ������)
//--------------------------------------------------------------
void UB_USB_MSC_HOST_Init(void)
{
  USB_MSC_HOST_STATUS=USB_MSC_DEV_DETACHED;
  USBH_Init(&USB_OTG_Core, USB_OTG_FS_CORE_ID, &USB_Host, &USBH_MSC_cb, &USR_Callbacks);
}



//--------------------------------------------------------------
// ������� USB HOST
// ��� ������� ������ ���������� ����������
// ������������ �������� :
//  USB_MSC_DEV_CONNECTED     , ���������� ���������� � ������
//  != USB_MSC_DEV_CONNECTED  , ���������� �� ����������
//
// ������ : ���� "USB_MSC_DEV_NOT_SUPPORTED", �������
//          ������������� ������ ���� ������� ��� ���
//           (��� ����� ������������ ������ ������)
//--------------------------------------------------------------
USB_MSC_HOST_STATUS_t UB_USB_MSC_HOST_Do(void)
{

  if(USB_MSC_HOST_STATUS!=USB_MSC_DEV_NOT_SUPPORTED) {
    // ����� ������ USB �� ��������������,
    // ������� �� ����� ����������
    USBH_Process(&USB_OTG_Core, &USB_Host);
  }

  return(USB_MSC_HOST_STATUS);
}




