/*
 * Author = Lino Mathew Samuel(C0728596), Hariprasad Athiparambath(C0727041), Athira Shajan(C0730123)
 *
 * @brief Semaphore
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <stdio.h>
#include "semphr.h"

/*xQueueHandle xQueue1;*/
xSemaphoreHandle Key = 0;


/********************************Delay******************************/

void dot(){
	unsigned long int i1,j1;
	for(j1=0;j1<100;j1++)for(i1=0;i1<30000;i1++);
	for(j1=0;j1<100;j1++)for(i1=0;i1<30000;i1++);
}


/******************************Resource needed to access**********************/


static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED0 state is off */
	Board_LED_Set(0, true);

	/* Initial LED1 state is off */
	Board_LED_Set(1, true);

	/* Initial LED2 state is off */
	Board_LED_Set(2, true);
}


/**************************Green_LED Task**********************************/


 void Green_LED( void *p )
{

 	 while(1)
 	 {
 		if (xSemaphoreTake(Key,1000)){
 			printf("Green LED Active\n");
 			prvSetupHardware();
 			Board_LED_Set(1, false);
 			dot();
 			Board_LED_Set(1, true);
 			xSemaphoreGive(Key);
 		}



 	 vTaskDelay(1);
 }
 }



 /**************************Red_LED Task**********************************/
 void Red_LED( void *p )
 {

  	 while(1)
  	 {
  		if (xSemaphoreTake(Key,1000)){
  			printf("Red LED Active\n");
  			prvSetupHardware();
  			Board_LED_Set(0, false);
  			dot();
  			Board_LED_Set(0, true);
  			xSemaphoreGive(Key);
  		}


 	 vTaskDelay(1);
 }
 }

 /**************************Blue_LED Task**********************************/

 void Blue_LED( void *p )
  {

   	 while(1)
   	 {
   		if (xSemaphoreTake(Key,1000)){
   			printf("Blue LED Active\n");
   			prvSetupHardware();
   			Board_LED_Set(2, false);
   			dot();
   			Board_LED_Set(2, true);
   			xSemaphoreGive(Key);
   		}


  	 vTaskDelay(1);
  }
  }



 int main(void)
 {

	 Key = xSemaphoreCreateMutex();

 	/* Blue_LED toggle thread */
 	xTaskCreate(Blue_LED, (signed char *) "Blue_LED",
 				configMINIMAL_STACK_SIZE, NULL, 1,
 				(xTaskHandle *) NULL);

 	/* Red_LED toggle thread */
	xTaskCreate(Red_LED, (signed char *) "Red_LED",
 				configMINIMAL_STACK_SIZE, NULL, 1,
 				(xTaskHandle *) NULL);
 	/* Green_LED toggle thread */
 	xTaskCreate(Green_LED, (signed char *) "Green_LED",
 	 				configMINIMAL_STACK_SIZE, NULL, 1,
 	 				(xTaskHandle *) NULL);


 	vTaskStartScheduler();


 	return 1;
 }

