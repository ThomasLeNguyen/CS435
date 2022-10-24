
#include "BusInOut.h"
#include "BusOut.h"
#include "DigitalIn.h"
#include "DigitalOut.h"
#include "PinNames.h"
#include "mbed.h"

#define BUTTON_1 D2 // PA10
#define BUTTON_2 D3 // PB3
#define BUTTON_3 D4 // PB5
#define BUTTON_4 D5 // PB4

#define RED_LED D6 // PB10
#define GREEN_LED D7 // PA8
#define BLUE_LED D8 // PA9


// Define the Input pins 
DigitalIn btn4(PB_4); // input pin
DigitalIn btn3(PB_5); // input pin
DigitalIn btn2(PB_3); // input pin
DigitalIn btn1(PA_10); // input pin

//Define the Output pins
DigitalOut red(PB_10); // output pin
DigitalOut green(PA_8); // output pin
DigitalOut blue(PA_9); // output pin

//Define Input/Output buses
BusIn Buttons(PA_10, PB_3, PB_5, PB_4);
BusOut LEDs(PB_10, PA_8, PA_9);

void ControlLED_DigitalIO ();
void ControlLED_BusIO ();


int main()
{
    while(1) {
        // ControlLED_DigitalIO ();
        ControlLED_BusIO ();
    }
}

// Part 1
void ControlLED_DigitalIO () {
    red.write((!btn4 && !btn3) ||
        (!btn4 && btn3 && btn2) ||
            (btn4 && btn3 && btn2 && btn1));
    green.write((!btn4 && btn3) ||
        (btn4 && !btn3) ||
            (btn4 && btn3 && btn2 && btn1));
    blue.write(btn4);
}

// Part 2
void ControlLED_BusIO () {
    switch (Buttons) {
        case 0 ... 3:
            LEDs = 0b001;
            break;
        case 4 ... 5:
            LEDs = 0b010;
            break;
        case 6 ... 7:
            LEDs = 0b011;
            break;
        case 8 ... 11:
            LEDs = 0b110;
            break;
        case 12 ... 14:
            LEDs = 0b100;
            break;
        case 15:
            LEDs = 0b111;
            break;
    }
}
