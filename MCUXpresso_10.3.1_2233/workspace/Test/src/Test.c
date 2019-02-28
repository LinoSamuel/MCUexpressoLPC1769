/*
===============================================================================
 Name        : Test.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

void dot(){
	unsigned long int i1,j1;

	for(j1=0;j1<100;j1++)for(i1=0;i1<30000;i1++);
	for(j1=0;j1<100;j1++)for(i1=0;i1<30000;i1++);
}

void dash(){
	unsigned long int i2,j2;

	for(j2=0;j2<100;j2++)for(i2=0;i2<60000;i2++);
	for(j2=0;j2<100;j2++)for(i2=0;i2<60000;i2++);
}


void gap(){
	unsigned long int i1,j1;

	for(j1=0;j1<100;j1++)for(i1=0;i1<200000;i1++);
}

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);

#endif
#endif

    // TODO: insert code here
    Chip_GPIO_WriteDirBit(LPC_GPIO, 0, 22, true); //init blue LED
        Chip_GPIO_WriteDirBit(LPC_GPIO, 3, 25, true); //init GREEN LED
        Chip_GPIO_WriteDirBit(LPC_GPIO, 3, 26, true); //init blue LED

        // TODO: insert code here
             Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
             Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 1);
             Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 1);


while(1){
	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 0);
	dot();
	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
	dot();
	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 0);
	dot();
	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 1);
	dot();
	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 0);
	dot();
	Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 1);
	dot();


}
    // Force the counter to be placed into memory
    // Enter an infinite loop, just incrementing a counter

    return 0 ;
}
