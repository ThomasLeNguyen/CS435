#include "mbed.h"

// Initialize the inputs from the sound detector:
AnalogIn audio(A0);
AnalogIn envelope(A1);
AnalogIn gate(A2);

// Initialize LEDs:
DigitalOut wrong(D7); // Red LED
DigitalOut right(D6); // Green LED

// Be able to use %f: 
Serial pc(D1,D0);

// Values we are going to use:
float a, sum1, sum2;
float data[128];

// This function will be used to get data
// We should be able to detect frequencies up to 2000hz (B6)
void getData() {
    int timeStart = us_ticker_read();
    // Create a for loop to get around 128 samples:
    for (int i=0; i < 128; i++) {
        a = audio.read() - 500; // Do a zero shift
        sum1 = sum1 + a;
        sum2 = sum2 + a * a; 

        //pc.printf("| sum1 = %f", sum1);
        //pc.printf("| sum2 = %f|", sum2);

        a = a * (sin(i * 3.14 / 128) * sin(i * 3.14 / 128)); // Apply Hann's window
        data[i] = 4 * a * (-1); // Store the data

        // Use this to check the values of the data in real-time
        // Comment out if not needed:
        //pc.printf("%f", data[i]);
        //pc.printf(" - %d\n", i);

        ThisThread::sleep_for(100);
    }

    int timeEnd = us_ticker_read();
    sum1 = sum1 / 128; 
    sum2 = sqrt(sum2 / 128);
    int sampling = 128000000 / (timeEnd - timeStart);

    /*
    pc.printf("\n\n %d", sampling);
    pc.printf("| sum1 = %f", sum1);
    pc.printf("| sum2= %f|", sum2);
    */

}

void FTT(uint16_t num, float freq) {
    // Write code here
}

int main() {
    // Create arrays consisting the note + it's frequency in Hz: 
    char *const notes[84] = {"C0", "C#", "D0", "D#", "E0", "F0", "F#", "G0", "G#", "A0", "A#", "B0", 
                            "C1", "C#1", "D1", "D#1", "E1", "F1", "F#1", "G1", "G#1", "A1", "A#1", "B1", 
                            "C2", "C#2", "D2", "D#2", "E2", "F2", "F#2", "G2", "G#2", "A2", "A#2", "B2", 
                            "C3", "C#3", "D3", "D#3", "E3", "F3", "F#3", "G3", "G#3", "A3", "A#3", "B3", 
                            "C4", "C#4", "D4", "D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4", 
                            "C5", "C#5", "D5", "D#5", "E5", "F5", "F#5", "G5", "G#5", "A5", "A#5", "B5", 
                            "C6", "C#6", "D6", "D#6", "E6", "F6", "F#6", "G6", "G#6", "A6", "A#6", "B6"};
    float notesVal[84] = {16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12, 24.50, 25.96, 27.50, 29.14, 30.87, 
                        32.70, 34.65, 36.71, 38.89, 41.20, 43.65, 46.25, 49.00, 51.91, 55.00, 58.27, 61.74, 
                        65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47, 
                        130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00, 233.08, 
                        246.94, 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 
                        466.16, 493.88, 523.25, 554.37, 587.33, 622.25, 659.25, 698.46, 739.99, 783.99, 830.61, 
                        880.00, 932.33, 987.77, 1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.91, 
                        1567.98, 1661.22, 1760.00, 1864.66, 1975.53};
    
    // Use this to make sure each note has it's proper value to the same index:
    /*
    for (int i = 0; i < 84; i++) {
        pc.printf("\n| %s = %f ", notes[i], notesVal[i]);
    }
    */

    // Generate a random note you want the user to play:
    srand(time(NULL));
    int randomNum = rand() % 84;
    pc.printf("\nI want you to play me: %s (%fHz). You have 5 seconds to play the note.", notes[randomNum], notesVal[randomNum]);
    pc.printf("\n5...");
    ThisThread::sleep_for(1000);
    pc.printf("\n4...");
    ThisThread::sleep_for(1000);
    pc.printf("\n3...");
    ThisThread::sleep_for(1000);
    pc.printf("\n2...");
    ThisThread::sleep_for(1000);
    pc.printf("\n1...");
    ThisThread::sleep_for(1000);
    pc.printf("\nPlay %s!", notes[randomNum]);

    getData(); // Initialize the data array with frequency values
    
    // Use this to perform FFT on the 128 samples in the data array:
    // Find the note in this function and output the result
    // FFT();
}