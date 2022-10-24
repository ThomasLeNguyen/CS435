/*----------------------------------------------------------------------------
LAB EXERCISE 4 - PART 1 Analog input and PWM
 ----------------------------------------
	Use two potentiometers to adjust the volume and pitch of the output sound wave.
	
	Inputs: potentiometers 1 and 2
	Output: speaker, PC

	GOOD LUCK!
 *----------------------------------------------------------------------------*/
#include "AnalogIn.h"
#include "PinNames.h"
#include "PwmOut.h"
#include "mbed.h"
#include <cstdio>

// Define the PWM speaker output
PwmOut speaker(D6);

// Define analog inputs
AnalogIn ain1(A0);
AnalogIn ain2(A1);


// Define variables
float i; // this is for saw-tooth

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
int main(){
	while(1){
		/*
		Create a saw-tooth sound wave (optional)
		Make the period and volume adjustable using the potentiometers
		*/
        speaker.period(ain1 * 1/320);
        speaker = ain2 * 1/320;
	}
}

// *******************************ARM University Program Copyright © ARM Ltd 2019*************************************
