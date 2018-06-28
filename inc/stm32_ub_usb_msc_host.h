//--------------------------------------------------------------
// File     : stm32_ub_usb_msc_host.h
//--------------------------------------------------------------

//--------------------------------------------------------------
#ifndef __STM32F1_UB_USB_MSCHOST_H
#define __STM32F1_UB_USB_MSCHOST_H


//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32f10x.h"
#include "usbh_usr.h"
#include "stm32_ub_fatfs.h"




//--------------------------------------------------------------
// ������ ���������� USB
//--------------------------------------------------------------
typedef enum {
  USB_MSC_HOST_NO_INIT =0,   // ��������� USB �� ��������������� 
  USB_MSC_DEV_DETACHED,      // ��� ������������� ����������
  USB_MSC_SPEED_ERROR,       // �������� USB �� ��������������
  USB_MSC_DEV_NOT_SUPPORTED, // ���������� �� ��������������
  USB_MSC_DEV_WRITE_PROTECT, // ���������� �������� �� ������
  USB_MSC_OVER_CURRENT,      // ���������� �� ����
  USB_MSC_DEV_CONNECTED      // ���������� ���������� � ������
}USB_MSC_HOST_STATUS_t;
USB_MSC_HOST_STATUS_t USB_MSC_HOST_STATUS;



//--------------------------------------------------------------
// ���������� �������
//--------------------------------------------------------------
void UB_USB_MSC_HOST_Init(void);
USB_MSC_HOST_STATUS_t UB_USB_MSC_HOST_Do(void);


//--------------------------------------------------------------
#endif // __STM32F1_UB_USB_MSCHOST_H
