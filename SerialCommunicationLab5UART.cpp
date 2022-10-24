#include "mbed.h"

Serial uart(D1, D0);

// Clear
void clear() {
    char clear[] = {0x1B, '[', '2', 'J', 0};
    uart.printf(clear);
}

// Home
void home() {
    char home[] = {0x1B, '[', 'H', 0};
    uart.printf(home);
}

// main() runs in its own thread in the OS
int main()
{
    uart.baud(9600);

    clear();
    home();

    int radius, height;
    
    uart.printf("\nEnter the radius: ");
    uart.scanf("%d", &radius);
    uart.printf("%d", radius);
    uart.printf("\nEnter the height: ");
    uart.scanf("%d", &height);
    uart.printf("%d", height);

    float volume = radius * radius * height * 3.14;

    uart.printf("\nVolume of the Cylinder: %f", volume);
}

/*
In this part, you are going to write a program that asks the user to enter the radius and height 
of a cylinder. The program then calculates the volume of the cylinder and displays it on the PC 
screen.
Programming the board:
    • Create a Serial port
    • Set the baud rate
    • Clear the screen and home the cursor
    • Enter the radius
    • Enter the height
    • Calculate the volume
    • Display the volume
On your PC:
    • There is a serial monitoring tool in Mbed Studio where you can see your message. 
    (Alternatively, you can open a terminal using other tools such as Terra Term or Putty. If 
    you are running your program with Mbed Studio and you would like to use Putty or Terra, 
    please remember to close mbed studio first after the program has 
    been downloaded into the board)
    • Setup the Serial Port and the baud rate
    • Connect the Nucleo F401RE Board to your PC using the USB cable (it should be already done)
    • In the terminal, enter the radius and height and check the volume.
*/