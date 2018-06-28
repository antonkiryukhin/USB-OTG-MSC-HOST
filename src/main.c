//--------------------------------------------------------------
// File     : main.c
// Datum    : 13.04.2013
// Version  : 1.0
// Autor    : UB
// EMail    : mc-4u(@)t-online.de
// Web      : www.mikrocontroller-4u.de
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.0
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Funktion : Demo der USB-MSC-HOST-Library
// Hinweis  : Diese zwei Files muessen auf 8MHz stehen
//              "cmsis_boot/stm32f4xx.h"
//              "cmsis_boot/system_stm32f4xx.c"
//--------------------------------------------------------------

#include "stm32f10x.h"
#include "stm32_ub_led.h"
#include "stm32_ub_usb_msc_host.h"

int main_usb(void)
{
  FIL myFile;   // обработчик файлов
  uint8_t write_ok=0;

  SystemInit(); // Инициализация настроек кварца

  // Инициализация светодиодов
 // UB_Led_Init();




  // Инициализация USB-OTG-порта как MSC-HOST
  // (для чтения / записи на USB флешку)
  UB_USB_MSC_HOST_Init();

  while(1)
  {
    // Данные о статусе USB
    if(UB_USB_MSC_HOST_Do()==USB_MSC_DEV_CONNECTED) {
      // если USB-флешка обнаружена
      //UB_Led_On(LED_GREEN);

      // Если файл еще не записан
      if(write_ok==0) {
       	write_ok=1;
       	//UB_Led_On(LED_RED);
		//Монтировать флешку
       	if(UB_Fatfs_Mount(MMC_0)==FATFS_OK) {  //Изм. с USB_0 на ММС_0!!!
          // Редактировать файл, записанный в корень флешки
          if(UB_Fatfs_OpenFile(&myFile, "USB_File.txt", F_WR_CLEAR)==FATFS_OK) {
            // Написать несколько строк текста в файле
            UB_Fatfs_WriteString(&myFile,"Write string 1");
            UB_Fatfs_WriteString(&myFile,"Write string 2");
            UB_Fatfs_WriteString(&myFile,"Write string 3");
            // Закрыть файл
            UB_Fatfs_CloseFile(&myFile);
          }
          // Размонтировать флешку
          UB_Fatfs_UnMount(MMC_0);		//Изм. с USB_0 на ММС_0!!!
        }
        //UB_Led_Off(LED_RED);
      }
    }
    else {
      // Если нет доступных USB флешек
      //UB_Led_Off(LED_GREEN);
    }
  }
}
