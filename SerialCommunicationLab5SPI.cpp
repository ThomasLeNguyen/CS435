/*----------------------------------------------------------------------------
LAB EXERCISE 5.3 - SPI interface
SERIAL COMMUNICATION
 ----------------------------------------
 Interface the LCD display using SPI protocol
	
	GOOD LUCK!
 *----------------------------------------------------------------------------*/
#include "mbed.h"
#include "NHD_0216HZ.h"

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main() {
  /*
    Intialise the SPI and the LCD 
    Print the first string
    Set the cursor to (0,1)
    Print the second string
  */

  init_lcd();
  init_spi();
  set_cursor(0, 0);
  print_lcd("Hello");
  set_cursor(0, 1);
  print_lcd("World");

}

// *******************************ARM University Program Copyright (c) ARM Ltd 2019*************************************
