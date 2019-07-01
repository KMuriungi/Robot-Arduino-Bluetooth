
#include <NewPing.h>

//ULTRASONIC SENSOR

#define TRIGGER_PIN  26  // Arduino pin : trigger pin on the ultrasonic sensor.
#define ECHO_PIN     24  // Arduino pin : echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in cm). 
                         //Maximum sensor distance is rated at (400-500)cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 8;
int in1 = 7;
int in2 = 6;
// motor two
int enB = 3;
int in3 = 5;
int in4 = 4;


int distance;


void setup()
{
  Serial.begin(9600);
  
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
 

void forward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
  analogWrite(enA, 200);
  }
void right()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
  }
void left()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200); 
  }
void wait()
{
   digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }
  
 void loop()
{
   
      delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
      Serial.print("Ping: ");
      Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
      Serial.println("cm");
      distance = sonar.ping_cm();
      while (distance >= 20)
      {
        forward();
        Serial.println("moving forward");
        delay(3000);
        distance = sonar.ping_cm();
        }
          wait();
          Serial.println("waiting");
          delay (5000);
 
}
