#include "mbed.h"

SPISlave device(D11, D12, D13, D9); //mosi, miso, sclk, cs

DigitalOut led(LED3);

int main()
{
   device.reply(0x00); // Prime SPI with first reply
   while (1)
   {
      if (device.receive())
      {
            int v = device.read(); // Read byte from master
            v = (v + 1) % 0x100;   // Add one to it, modulo 256
            printf("receive: v = 0x%X\n", v);
            device.reply(v); // Make this the next reply
            led = !led;      // led turn blue/orange if device receive
      }
   }
}