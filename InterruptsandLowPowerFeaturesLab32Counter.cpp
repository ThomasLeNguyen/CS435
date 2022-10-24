/*----------------------------------------------------------------------------
LAB EXERCISE 3.2 - INTERRUPT IN/OUT - Counters
PROGRAMMING USING MBED API
 ----------------------------------------
In this exercise you will need to write some code so that it counts the number of times a button has been pressed and 
lights up the RGB LED. This will correspond to the button which has been pressed the most.
    •	Button 1 corresponds to the Red LED
    •	Button 2 corresponds to the Green LED
    •	Button 3 corresponds to the Blue LED
    •	Button 4 is used to reset all the counters and turn off all the LEDs.
Also, if several buttons have been pressed the same number of times their respective LEDs should all be ON simultaneously. 

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

// Define counters
int redCount = 0;
int greenCount = 0;
int blueCount = 0;

void updateLEDs() {
    red.write(redCount >= greenCount && redCount >= blueCount && redCount > 0);
    green.write(greenCount >= redCount && greenCount >= blueCount && greenCount > 0);
    blue.write(blueCount >= redCount && blueCount >= greenCount && blueCount > 0);
}


// Define ISRs for the interrupts
void button_1_handler() {
	redCount++;
    updateLEDs();
}

void button_2_handler() {
	greenCount++;
    updateLEDs();
}

void button_3_handler() {
	blueCount++;
    updateLEDs();
}

void button_4_handler() {
	redCount = 0, greenCount = 0, blueCount = 0;
    red = 0, green = 0, blue = 0;
    updateLEDs();
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main() {
	
	__enable_irq();
	
	// initially turn off all LEDs and set all the counters to 0
	button_4_handler();

	// Interrupt handlers
    btn1.rise(&button_1_handler);
    btn2.rise(&button_2_handler);
    btn3.rise(&button_3_handler);
    btn4.rise(&button_4_handler);

	// Sleep on exit
	while(1) {
        __wfi();
    }
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
