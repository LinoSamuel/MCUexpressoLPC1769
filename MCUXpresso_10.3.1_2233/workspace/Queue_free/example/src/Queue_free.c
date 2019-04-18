/*
* @brief FreeRTOS Blinky example
*
* @note
* Copyright(C) NXP Semiconductors, 2014
* All rights reserved.
*
* @par
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* LPC products. This software is supplied "AS IS" without any warranties of
* any kind, and NXP Semiconductors and its licensor disclaim any and
* all warranties, express or implied, including all implied warranties of
* merchantability, fitness for a particular purpose and non-infringement of
* intellectual property rights. NXP Semiconductors assumes no responsibility
* or liability for the use of the software, conveys no license or rights under
any
* patent, copyright, mask work right, or any other intellectual property rights
in
* or to any products. NXP Semiconductors reserves the right to make changes
* in the software without notification. NXP Semiconductors also makes no
* representation or warranty that such application will be suitable for the
* specified use without further testing or modification.
*
* @par
* Permission to use, copy, modify, and distribute this software and its
* documentation is hereby granted, under NXP Semiconductors' and its
* licensor's relevant copyrights in the software, without fee, provided that it
* is used in conjunction with NXP Semiconductors microcontrollers. This
* copyright, permission, and disclaimer notice must appear in all copies of
* this code.
*/
#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <stdio.h>





xQueueHandle xQueue1;
void dot(){
unsigned long int i1,j1;
for(j1=0;j1<100;j1++)for(i1=0;i1<30000;i1++);
for(j1=0;j1<100;j1++)for(i1=0;i1<30000;i1++);
}

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
/**************************Sender Task**********************************/
void sender_task( void *p )
{
int i =0;
while(1)
{
printf("Send %i to receiver task\n",i);
if(xQueueSend(xQueue1,&i, (portTickType) 1000)){
printf("Cannot Send to the queue\n");
}
i++;
if (i>2){
i=0;
vTaskDelay(30000);
}
vTaskDelay(10000);
}
}
/**************************Receiver Task**********************************/
void receiver_task( void *p )
{
int rx_int =0;
while(1)
{
if (xQueueReceive( xQueue1, &rx_int, (portTickType) 3000 )){
printf("Received %i from Sender task\n",rx_int);

Board_LED_Set(rx_int, false);
dot();
Board_LED_Set(rx_int, true);
}
else
{
printf("Queue is Empty\n");
}
}
vTaskDelay(30000);
}
int main(void)
{
prvSetupHardware();
xQueue1 = xQueueCreate(5, sizeof(int));
/* LED toggle thread */
xTaskCreate(sender_task, (signed char *) "sender_task",
configMINIMAL_STACK_SIZE, NULL, 3,
(xTaskHandle *) NULL);
xTaskCreate(receiver_task, (signed char *) "receiver_task",
configMINIMAL_STACK_SIZE, NULL, 4,
(xTaskHandle *) NULL);
vTaskStartScheduler();
return 1;
}
