#include "mbed.h"

     Thread thread1;

     //master

     SPI spi(D11, D12, D13); // mosi, miso, sclk
     DigitalOut cs(D9);

void master()
{
   // Chip must be deselected
   cs = 1;

   // Setup the spi for 8 bit data, high steady state clock,
   // second edge capture, with a 1MHz clock rate
   spi.format(8, 3);
   spi.frequency(1000000);

   // Select the device by seting chip select low
   cs = 0;

   // Send 0x8f, the command to read the WHOAMI register
   spi.write(0x8F);

   // Send a dummy byte to receive the contents of the WHOAMI register
   int whoami = spi.write(0x00);
   printf("WHOAMI register = 0x%X\n", whoami);

   // Deselect the device
   cs = 1;
}


int main()
{
   thread1.start(master);
}