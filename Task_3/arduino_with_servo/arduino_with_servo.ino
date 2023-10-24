/******************************************************/
/**********Author:       Kareem Amr Ahmed Mokhtar *****/
/**********File name:    Task_3 EVER              *****/
/**********Date:         24/10/2023               *****/
/******************************************************/
#include <Servo.h>
#include <SoftwareSerial.h>

#define servoPin   9
#define buttonPin  5 

Servo myservo;
SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  myservo.attach(servoPin);
  //Serial.begin(9600);
  mySerial.begin(9600); // SoftwareSerial
}

void loop()
{	
  
 if (mySerial.available() > 0) {
    
    int servoAngle = mySerial.read();
	//Serial.println(servoAngle);
    // Control servo
    myservo.write(servoAngle);

    delay(100);
  }
  if(digitalRead(buttonPin))
  {
  Serial.write(1);
  delay(500);
   }
  else
  {  Serial.write(0);
  }
  //Serial.write(digitalRead(buttonPin));
}
