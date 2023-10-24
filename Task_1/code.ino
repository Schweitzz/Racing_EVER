/******************************************************/
/**********Author:       Kareem Amr Ahmed Mokhtar *****/
/**********File name:    Task_1 EVER              *****/
/**********Date:         14/10/2023               *****/
/******************************************************/

#include <LiquidCrystal.h>
//LCD Pins configuration
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//Ultra sonic sensor pins configuration
const int echoPin = A5; 
const int trigPin = 7; 

const int buttonPin = 2;

//flag and counter intialization
int buttonPressed = 0;
int counter=0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
  //inturupt configuration
  attachInterrupt(digitalPinToInterrupt(buttonPin), measureAndDisplayDistance, RISING);

  lcd.begin(16, 2);
}

void loop() {
	lcd.clear();
  lcd.print("press to get distance");
  delay(2500);
  if(buttonPressed ==0){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("0  state:off");}
  
   for( counter=0;counter<=7;counter++)
  {
    int previousmillis=millis();
    //delay
    while(millis()-previousmillis<1000)
    {}
    lcd.setCursor(counter, 1);
    lcd.print(counter);
     previousmillis=millis();
  }
  //flag reset
  buttonPressed = 0;
}
//ISR function
void measureAndDisplayDistance() {
  //distance calculation
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;  
  
  //displaying distance
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(distance);
  lcd.print("cm");
  lcd.print(" state:on");
  delay(2000);
  counter=0;
  //disable zero state
  buttonPressed = 1;
}
