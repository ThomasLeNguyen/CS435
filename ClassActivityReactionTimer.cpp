#include "ThisThread.h"
#include "mbed.h"

DigitalIn btn(PC_13);
DigitalOut led(PA_5);
Timer t;
int timer;

int main() {
    int r;
    printf("Press the button as soon as you see the light...\n");
    while (true) {
        t.reset();
        r = rand() % 10;
        ThisThread::sleep_for(r * 1000);
        t.start();

        led = 1;
        ThisThread::sleep_for(50ms);
        
        while (btn == 1) {}

        t.stop();
        led = 0;
        timer = t.read_ms();
        printf("The time taken was %d milliseconds\n", timer);
        ThisThread::sleep_for(3000ms);
    }
}
