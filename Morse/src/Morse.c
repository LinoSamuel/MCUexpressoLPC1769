/*
===============================================================================
 Name        : Morse.c
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
	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 0);
	for(j1=0;j1<100;j1++)for(i1=0;i1<30000;i1++);
	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
}

void dash(){
	unsigned long int i2,j2;

	for(j2=0;j2<100;j2++)for(i2=0;i2<60000;i2++);
	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 0);
	for(j2=0;j2<100;j2++)for(i2=0;i2<60000;i2++);
	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
}


void gap(){
	unsigned long int i1,j1;

	for(j1=0;j1<100;j1++)for(i1=0;i1<200000;i1++);
	Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
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

    char input[100];
       int index;
while(1){
       printf( "\n Enter Message to transmit the Morse code :");
       gets(input);
       for(index =0; input[index] !='\0'; index++) {
    	   printf("%c",input[index]);
    	   switch(input[index]) {
    	         case 'A' :
    	            dot();
    	            dash();
    	            break;
    	         case 'B' :
    	        	 dash();
    	        	 dot();
    	        	 dot();
    	        	 dot();
    	        	 break;
    	         case 'C' :
    	            dash();
    	            dot();
    	            dash();
    	            dot();
    	            break;
    	         case 'D' :
    	            dash();
    	            dot();
    	            dot();
    	            break;
    	         case 'E' :
    	            dot();
    	            break;
    	         case 'F' :
    	            dot();
    	            dot();
    	            dash();
    	            dot();
    	            break;
    	         case 'G' :
    	            dash();
    	            dash();
    	            dot();
    	            break;
    	         case 'H' :
    	            dot();
    	            dot();
    	            dot();
    	            dot();
    	            break;

    	         case 'I' :
    	            dot();
    	            dot();
    	            break;

    	         case 'J' :
    	            dot();
    	            dash();
    	            dash();
    	            dash();
    	            break;
    	         case 'K' :
    	            dash();
    	            dot();
    	            dash();
    	            break;
    	         case 'L' :
    	            dot();
    	            dash();
    	            dot();
    	            dot();
    	            break;
    	         case 'M' :
    	            dash();
    	            dash();
    	            break;
    	         case 'N' :
    	            dash();
    	            dot();
    	            break;

    	         case 'O' :
    	            dash();
    	            dash();
    	            dash();
    	            break;
    	         case 'P' :
    	            dot();
    	            dash();
    	            dash();
					dot();
    	            break;
    	         case 'Q' :
    	            dash();
    	            dash();
    	            dot();
    	            dash();
    	            break;
    	         case 'R' :
    	            dot();
    	            dash();
    	            dot();
    	            break;
    	         case 'S' :
    	            dot();
    	            dot();
    	            dot();
    	            break;
    	         case 'T' :
    	        	 dash();
    	            break;
    	         case 'U' :
    	        	 dot();
    	        	 dot();
    	        	 dash();
    	        	 break;
    	         case 'V' :
    	              dot();
    	              dot();
    	              dot();
    	              dash();
    	              break;
    	         case 'W' :
    	        	 dot();
    	        	 dash();
    	        	 dash();
    	        	 break;
    	         case 'X' :
    	        	 dash();
    	        	 dot();
    	        	 dot();
    	        	 dash();
    	        	 break;
    	         case 'Y' :
    	        	 dash();
    	        	 dot();
    	        	 dash();
    	        	 dash();
    	        	 break;

    	         case 'Z' :
    	        	 dash();
    	        	 dash();
    	        	 dot();
    	        	 dot();
    	             break;

    	         default :
    	            gap();
    	      }

       }

}
    // Force the counter to be placed into memory
    // Enter an infinite loop, just incrementing a counter

    return 0 ;
}
