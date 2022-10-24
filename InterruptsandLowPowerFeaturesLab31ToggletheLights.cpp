/*----------------------------------------------------------------------------
LAB EXERCISE 3.1 - INTERRUPT IN/OUT
PROGRAMMING USING MBED API
----------------------------------------
In this exercise you need to use the Mbed API functions to:
   1) Define InterruptIn and ISR for each button press
   2) In the interrupt service routine, the RGB LED is used to indicate when a
   button was pressed:
           + Button 1 - light RED
           + Button 2 - light BLUE
           + Button 3 - light GREEN
           + Button 4 - light WHITE (RED, GREEN and BLUE at the same time)
          
   3) Put the processor into sleep mode upon exiting from the ISR
          
   GOOD LUCK!
*----------------------------------------------------------------------------*/
#include "mbed.h"
 
#define BUTTON_1 D2 // PA_10
#define BUTTON_2 D3 // PB_3
#define BUTTON_3 D4 // PB_5
#define BUTTON_4 D5 // PB_4
 
#define RED_LED D6 // PB_10
#define GREEN_LED D7 // PA_8
#define BLUE_LED D8 // PA_9
 
// Define outputs
DigitalOut red(PB_10);
DigitalOut green(PA_8);
DigitalOut blue(PA_9);
 
 
// Define interrupt inputs
InterruptIn btn1(PA_10);
InterruptIn btn2(PB_3);
InterruptIn btn3(PB_5);
InterruptIn btn4(PB_4);
 
// Define ISRs for the interrupts
void button_1_handler() {
   red = !red;
}

void button_2_handler() {
   green = !green;
}

void button_3_handler() {
   blue = !blue;
}

void button_4_handler() {
   red = 1, green = 1, blue = 1;
}

/*----------------------------------------------------------------------------
MAIN function
*----------------------------------------------------------------------------*/
 
int main() {
  
   __enable_irq();         // enable interrupts
  
   // initially turn off all LEDs
   red = 0, green = 0, blue = 0;
  
   // Interrupt handlers
   // Attach the address of the ISR to the rising edge
   btn1.rise(&button_1_handler);
   btn2.rise(&button_2_handler);
   btn3.rise(&button_3_handler);
   btn4.rise(&button_4_handler);
  
   // leep on exit
   while(1) {
       __wfi();
   }
}
 
// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
