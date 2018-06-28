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
//            Данная библиотека только создает USB-HOST
//            для управления данными используется библиотека
//            "stm32_ub_fatfs" (USB-версия)
//
// Ссылки   : Некоторые флэш-накопители USB не поддерживаются
//            У автора есть флешка Intenso 4GB, которая работает
//            Sandisk 8GB не работает !!
//
//            модуль Discovery работает только в режиме
//            USB-FullSpeed-Mode (USB-High-Speed не работает)

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
// Глобальные переменные
//--------------------------------------------------------------
USB_OTG_CORE_HANDLE          USB_OTG_Core;
USBH_HOST                    USB_Host;




//--------------------------------------------------------------
// Инициализация USB OTG порт, как MSC-Host
// (Host закрыт для съемных носителях, таких как USB флешки)
//--------------------------------------------------------------
void UB_USB_MSC_HOST_Init(void)
{
  USB_MSC_HOST_STATUS=USB_MSC_DEV_DETACHED;
  USBH_Init(&USB_OTG_Core, USB_OTG_FS_CORE_ID, &USB_Host, &USBH_MSC_cb, &USR_Callbacks);
}



//--------------------------------------------------------------
// Функция USB HOST
// Эта функция должна вызываться циклически
// Возвращаемое значение :
//  USB_MSC_DEV_CONNECTED     , Устройство подключено и готово
//  != USB_MSC_DEV_CONNECTED  , Устройство не подключено
//
// Ссылка : Если "USB_MSC_DEV_NOT_SUPPORTED", функция
//          инициализации должна быть вызвана еще раз
//           (или нужно использовать другую флешку)
//--------------------------------------------------------------
USB_MSC_HOST_STATUS_t UB_USB_MSC_HOST_Do(void)
{

  if(USB_MSC_HOST_STATUS!=USB_MSC_DEV_NOT_SUPPORTED) {
    // когда флешка USB не поддерживается,
    // функция не будет вызываться
    USBH_Process(&USB_OTG_Core, &USB_Host);
  }

  return(USB_MSC_HOST_STATUS);
}




