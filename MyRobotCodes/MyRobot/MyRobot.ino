const int trigPin = 8;
const int echoPin = 9;
const int buzzer = 7;
const int greenLed = 4;
const int yellowLed = 3;
const int redLed = 10;

const int motorRight = 11;
const int motorLeft = 12;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  pinMode(motorRight, OUTPUT);
  pinMode(motorLeft, OUTPUT);
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
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    Serial.println("Object Detected!!!");
    
    Stop();
    Serial.println("Robot Stopped");
    delay(2000);
    
    right();
    Serial.println("Robot Moving Right");
    delay(2000);
    
    left();
    Serial.println("Robot Moving Left");
    delay(2000);
 
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
    digitalWrite(redLed, LOW);
    Serial.println("No Obstacle Detected!!!");

    forward();
    Serial.println("Robot Moving Forward");
    
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

void forward()          //Moving Forward function
{
  analogWrite(motorRight,HIGH);
  analogWrite(motorLeft,HIGH);
}

void right()            //Moving Right function
{
  analogWrite(motorRight,LOW);
  analogWrite(motorLeft,HIGH);
}

void left()              //Moving Left function
{
  analogWrite(motorRight,HIGH);
  analogWrite(motorLeft,LOW);
}

void Stop()              //Moving Stop function
{
  analogWrite(motorRight,LOW);
  analogWrite(motorLeft,LOW);
}

 
