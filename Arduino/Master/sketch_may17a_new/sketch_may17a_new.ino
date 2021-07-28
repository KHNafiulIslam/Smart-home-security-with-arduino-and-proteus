#include<Wire.h>
#include <dht.h> 

dht DHT;
byte Temparature;
//master
void setup() {
  Wire.begin();
  //RGD LED pin 5,6,7
  pinMode(5, OUTPUT);//blue
  pinMode(6, OUTPUT);//green
  pinMode(7, OUTPUT);//red
  //Ultrasonic sensor 12,11
  pinMode(12, OUTPUT); // Sets the trigPin as an Output 
  pinMode(11, INPUT); // Sets the echoPin as an Input  

  
  Serial.begin(9600);
}

void loop() 
{
 DHT.read11(A0);
 // Clears the trigPin 
 digitalWrite(12, LOW); 
 delayMicroseconds(2); 
 // Sets the trigPin on HIGH state for 10 micro seconds 
 digitalWrite(12, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(12, LOW); 
 
// Reads the echoPin, returns the sound wave travel time in microseconds 
 long duration = pulseIn(11, HIGH); 
 // Calculating the distance 
 long distance= (duration*0.034)/2; //The speed of sound is 340 meter/second or 0.0343 cm/microsecond
 //if the temperature is more than 35, we will see blue
 if(DHT.temperature > 35){
 digitalWrite(5,HIGH);//the blue light
 digitalWrite(6,LOW);
 digitalWrite(7,LOW);
 }
 //if the temperature is less than 35, we will see red
 else
 {
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 digitalWrite(7,HIGH);//the red light
 }
 
 Serial.print("Temperature = "); 
 Serial.print(DHT.temperature); 
 Temparature = DHT.temperature; 
 Serial.print("C and ");
 Serial.print("Distance = ");
 Serial.print(distance);
 Serial.println(" cm");
 Wire.beginTransmission(100);
 Wire.write(Temparature);
 Wire.endTransmission(100);
 delay(200); 
}
