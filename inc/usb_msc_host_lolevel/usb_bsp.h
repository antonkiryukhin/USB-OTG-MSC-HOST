//--------------------------------------------------------------
// File     : usb_bsp.h
//--------------------------------------------------------------


#ifndef __USB_BSP__H__
#define __USB_BSP__H__

//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "misc.h"
#include "usb_core.h"





#define TIM_MSEC_DELAY       0x01
#define TIM_USEC_DELAY       0x02



#define HOST_POWERSW_PORT_RCC              RCC_APB2Periph_GPIOB
#define HOST_POWERSW_PORT                  GPIOB
#define HOST_POWERSW_VBUS                  GPIO_Pin_8


void USB_OTG_BSP_Init (USB_OTG_CORE_HANDLE *pdev);
void USB_OTG_BSP_uDelay (const uint32_t usec);
void USB_OTG_BSP_mDelay (const uint32_t msec);
void USB_OTG_BSP_EnableInterrupt (USB_OTG_CORE_HANDLE *pdev);

void USB_OTG_BSP_ConfigVBUS(USB_OTG_CORE_HANDLE *pdev);
void USB_OTG_BSP_DriveVBUS(USB_OTG_CORE_HANDLE *pdev,uint8_t state);



#endif //__USB_BSP__H__


