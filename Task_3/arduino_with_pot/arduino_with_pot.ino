/******************************************************/
/**********Author:       Kareem Amr Ahmed Mokhtar *****/
/**********File name:    Task_3 EVER              *****/
/**********Date:         24/10/2023               *****/
/******************************************************/
#include <SoftwareSerial.h>

#define ledPin    12
#define potWiper  A0 

int Led_state=0;
int Pot_value=0;

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(potWiper, INPUT);
  //Serial.begin(9600);
  mySerial.begin(9600); // SoftwareSerial
}

void loop()
{	
  Pot_value=analogRead(potWiper);
  int Mapped_value=map(Pot_value,0,1023,0,180);
  mySerial.write(Mapped_value);
  
  delay(100);
  if(mySerial.available()>0)
  {
  	Led_state=mySerial.read();
  	digitalWrite(ledPin,Led_state);
    delay(1000);
  }
}