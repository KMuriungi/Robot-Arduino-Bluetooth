#include <LiquidCrystal.h>
 
LiquidCrystal lcd(11, NULL, 12, 7, 8, 9, 10); //create the lcd variable
 
const int trigPin = 26;
const int echoPin = 24;
const int buzzer = 50;
const int greenLed = 46;
const int yellowRight = 44;
const int yellowLeft = 30;
const int redRight = 48;
const int redLeft = 28;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowRight, OUTPUT);
  pinMode(yellowLeft, OUTPUT);
  pinMode(redRight, OUTPUT);
  pinMode(redLeft, OUTPUT);

  lcd.clear();                    //clear the LCD during setup
  lcd.begin(16,2);                //define the columns (16) and rows (2)
}

void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if (cm == 0) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(yellowRight, HIGH);
    digitalWrite(yellowLeft, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(redRight, HIGH);
    digitalWrite(redLeft, HIGH);
    Serial.println("Object Detected!!!");

    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("OBJECT");
    lcd.setCursor(2,1);
    lcd.print("DETECTED !!!");
  }
 
  
  /*
  else if(cm == 2){
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
    delay(1000);
    digitalWrite(yellowLed, LOW);
    } 

    */
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowRight, LOW);
    digitalWrite(yellowLeft, LOW);
    digitalWrite(redRight, LOW);
    digitalWrite(redLeft, LOW);
    Serial.println("No Obstacle Detected!!!");

    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("NO OBJECT");
    lcd.setCursor(2,1);
    lcd.print("DETECTED !!!");

  }
  
  delay(100);
}



long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

