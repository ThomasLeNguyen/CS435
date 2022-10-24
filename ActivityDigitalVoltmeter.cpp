#include "AnalogIn.h"
#include "ThisThread.h"
#include "mbed.h"
Serial pc(D1, D0); // tx, rx

AnalogIn in(A0);

int main() {
    float value;
    pc.printf("Hello World!\n");
    pc.printf("\n\rValue = %f\n\r", value);

    while (true) {
        value = in.read();
        value *= 3300;

        pc.printf("\n\rValue = %f\n\r", value);

        ThisThread::sleep_for(1000);
    }
}