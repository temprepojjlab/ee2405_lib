#include"mbed.h"

Thread thread1;
Thread thread2;

BufferedSerial pc(USBTX,USBRX); //tx,rx
BufferedSerial uart(D1,D0); //tx,rx
DigitalIn button(USER_BUTTON);

void recieve_thread(){
   while(1) {
      if(uart.readable()){
         char recv[1];
         uart.read(recv, sizeof(recv));
         // print out the recieved data
         pc.write(recv, sizeof(recv));
         printf("\r\n");
      }
   }
}

void send_thread(){
   while(1){
      // if button is pressed
      if(button == 0){
         char s[] = "image_classification\0";
         uart.write(s, sizeof(s));
         printf("send\r\n");
         ThisThread::sleep_for(1s);
      }
   }
}

int main(){
   uart.set_baud(9600);
   thread1.start(send_thread);
   thread2.start(recieve_thread);
}