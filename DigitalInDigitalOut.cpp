/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "iostream"
#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalIn myButton(PC_13);
    DigitalOut myLed(PA_5);

    while (true) {
        myLed = !myLed;
        ThisThread::sleep_for(BLINKING_RATE);
    }
/*
    while (true) {
    if (myButton == 1) {
        myLed = 0;
        cout << "0";
    } else {
        myLed = 1;
        cout << "1";
    }

    }
    */
}
