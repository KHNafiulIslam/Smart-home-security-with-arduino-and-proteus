#include <VirtualWire.h> 
int i; 
//slave 1
void setup() 
{ 
 Serial.begin(9600);
 //for rf module RX 
 vw_set_ptt_inverted(true); 
 vw_setup(2000); 
 vw_set_rx_pin(11); 
 vw_rx_start(); 
} 
 
void loop() 
{ 
  //getting data using RF module communication
 uint8_t buf[VW_MAX_MESSAGE_LEN]; 
 uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 if (vw_get_message(buf, &buflen)) 
 { 
 char ch = buf[0];
 if(ch == '1')
 {
 for ( i = 1; i < buflen; i++) 
 { 
 byte ch = (byte)buf[i]; 
 Serial.print("Receiver A: Temperature = ");
 Serial.print(ch); 
 Serial.print("C"); 
 Serial.println(); 
 }
   } 
  }
 }
