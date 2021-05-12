#include "mbed.h"

AnalogIn Ain(A0);
float ADCdata;

int main()
{
    while (1)
    {
        ADCdata = Ain; //send an opening text message
        ThisThread::sleep_for(500ms);
        printf("%f\r\n", ADCdata);
        //send data to the terminal
    }
}