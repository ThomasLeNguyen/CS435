#include "mbed.h"

// define I2C and serial interfaces: pc and temp_sensor
// temp sensor I2C SCL = D15
// temp sensor I2C SDA = D14
I2C temp_sensor(D14, D15);
Serial myPC(D1, D0);

const int temp_addr = 0x90;  // I2C address of temperature sensor

// declare array to hold needed commands: convert T command and read temperature command
// start convert T, stop convert T, read temperature
char cmds[2] = {0x51, 0xAA};

// declare array to hold 16-bit temperature data (MSByte and LSByte)
char MSByte;
char LSByte;
char temp_data[2] = {MSByte, LSByte};

// Clear
void clear() {
    char clear[] = {0x1B, '[', '2', 'J', 0};
    myPC.printf(clear);
}

// Home
void home() {
    char home[] = {0x1B, '[', 'H', 0};
    myPC.printf(home);
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
int main() {
    while(1) {
        // Write the Start Convert T command to the sensor and wait for 500 ms
        temp_sensor.write(temp_addr, &cmds[0], 1);
        wait_us(5000000);

		// Write the Read Temperature command to the sensor
        temp_sensor.write(temp_addr, &cmds[1], 1);

		// Read the 16-bit temperature data
        temp_sensor.read(temp_addr, temp_data, 2);

		// Convert temperature to Celsius
        float temp = (float((temp_data[0] << 8) | temp_data[1]) / 256);

		// Print temperature to the serial monitor
	    myPC.baud(9600);
	    clear();
	    home();
	   
	    myPC.printf("\nCurrent Temperature in Celcius: %f", temp);

	}
}