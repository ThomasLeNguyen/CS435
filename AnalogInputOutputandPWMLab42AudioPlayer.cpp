/*----------------------------------------------------------------------------
LAB EXERCISE 4 -PART 2 - TICKER AND PWM
 ----------------------------------------
Make an audio player to play a music

Output: PWM Speaker (play the music)

GOOD LUCK!

*----------------------------------------------------------------------------*/

#include "PwmOut.h"
#include "ThisThread.h"
#include "mbed.h"
#include "mbed_chrono.h"
#include "mbed_wait_api.h"
#include <cstdio>

#define SPEAKER D6

//Define the frequency of basic music notes
#define Do 523.251
#define Re 587.330
#define Mi 659.255
#define Fa 698.467
#define So 783.991
#define La 880.000
#define Si 987.767
#define No 001.000

//Define the beat length (e.g. whole note, half note) 
# define b1     0.5
# define b2     0.25
# define b3     0.125
# define b4     0.075

//Define the musical piece
float note[] = {Mi,No,Mi,No,Mi,No, Mi,No,Mi,No,Mi,No, Mi,No,So,No,Do,No,Re,No,Mi,No, 
    Fa,No,Fa,No,Fa,No,Fa,No, Fa,No,Mi,No,Mi,No,Mi,No,Mi,No, Mi,Re,No,Re,Mi, Re,No,So,No};
float beat[] = {b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b3,b3,b3,b3,b2,b1, 
    b3,b3,b3,b3,b3,b3,b3,b3, b3,b3,b3,b3,b3,b3,b4,b4,b4,b4, b2,b3,b3,b2,b2, b2,b2,b2,b2};

// Define the PWM output for the speaker
PwmOut speaker(D6);

// Define the time ticker
Ticker flipper;

// Static variable to iterate through note and beat arrays
static int k = 0;

/*----------------------------------------------------------------------------
 Interrupt Service Routine
 *----------------------------------------------------------------------------*/
// Define the ticker ISR
void timer_ISR(){ 
	/*
	The time ticker ISR will be periodically triggered after every single note.
        To do that: 
        -  Update the PWM frequency to that of kth music note
        -  increment k to consider the next music note 
        -  reconfigure the tick interrupt time based on the beat length of kth music note
	*/

    if (k >= 49)
        k = 0;

    printf("no");

    speaker.period(note[k]);
    speaker = 0.5;

    printf("hi");

    ThisThread::sleep_for(beat[k]);

    k++;
} 

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
int main() {
    k = 0;  // start by considering the first music note
    // Initialize ticker to call timer_ISR after 0.1 seconds
    flipper.attach(&timer_ISR, 100ms);
    // sleep and wait for recurring interrupts
    while(true)
        __wfi();
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
