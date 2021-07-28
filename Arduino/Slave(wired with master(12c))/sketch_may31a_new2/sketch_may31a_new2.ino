#include <VirtualWire.h>
#include <VirtualWire_Config.h>
#include<Wire.h>
//wired slave with 12c
byte data;//this data will get by the 12c protocol from master

void setup() 
{ 
 //rf module TX communication
 vw_set_ptt_inverted(true); 
 vw_setup(2000); 
 vw_set_tx_pin(12); 
 pinMode(7,INPUT);//for button 1 pin 7
 pinMode(6,INPUT);//for button 2 pin 6
 pinMode(5,INPUT);//for button 3 pin 5
 
 Wire.begin(100);
 Wire.onReceive(myfunction);
} 
 
void loop() 
{ 
 int bt1 = digitalRead(7);
 int bt2 = digitalRead(6);
 int bt3 = digitalRead(5);
 delay(200);
 //if we click button 1, rf module send data for slave 1
 if(bt1 == 1){
 char msg1[2];
 msg1[0]='1';
 msg1[1]=(char)data; 
 vw_send((uint8_t *)msg1, 2);
 delay(1000); //delay of 3 seconds 
}
//if we click button 2, rf module send data for slave 2
if(bt2 == 1){
 char msg2[2];
 msg2[0]='2';
 msg2[1]=(char)data; 
 vw_send((uint8_t *)msg2, 2); 
 delay(1000); //delay of 3 seconds 
}
//if we click button 3, rf module send data for slave 3
if(bt3 == 1){
 char msg3[2];
 msg3[0]='3';
 msg3[1]=(char)data; 
 vw_send((uint8_t *)msg3, 2); 
 delay(1000); //delay of 3 seconds 
}
}

void myfunction()
{
  while (Wire.available()>0)
  {
    //getting the data from master
    data = (byte)Wire.read();
  }
}
