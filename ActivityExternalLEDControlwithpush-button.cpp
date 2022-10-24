/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "PinNamesTypes.h"
#include "ThisThread.h"
#include "mbed.h"
#include <iostream>

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalIn btn(PA_3);
    DigitalOut led(PB_5);

    while (true) {
        if (btn == 0) {
            led = 0;
            printf("led 0\n");
        } else {
            led = 1;
            printf("led 1\n");
        }

        ThisThread::sleep_for(BLINKING_RATE);

        //printf("run\n");
    }
}
