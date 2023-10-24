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
//SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  pinMode(servoPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  myservo.attach(servoPin);
  Serial.begin(9600);
 // mySerial.begin(9600); // SoftwareSerial
}

void loop()
{	
 if (Serial.available() > 0) {
    // Read the potentiometer value from master
    int servoAngle = Serial.read();

    // Control servo
    myservo.write(servoAngle);

    delay(100);
  }
  Serial.write(digitalRead(buttonPin));
}