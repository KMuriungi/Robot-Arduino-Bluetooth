/* This is a 2 wheel robot bluetooth controlled 
 * robot with L298N motor driver.
 * It has Ultrasonic Sensor which can assist 
 * during automatic mode when bluetooth is not 
 * used to control
 * 
 * Most of the events have been written as  function to make the code 
 * shorter and simpler to understand.
 * 
 * The code written in FUNCTIONS can be used in 
 * both Automatic and Bluetooth Control.
 * 
 * Tuesday 7th March 2017 ... start
 * Friday 28th April 2017 ... Final Code
 * By Kithinji A. Muriungi | www.muriungi.com | www.kithinjimuriungi.wordpress.com &&
 * By Mukuzi David 
 * kithinjimuriungi@yahoo.com && dmukuzi@gmail.com
 * Twitter << @kamkith >>
 * Facebook << Kithinji Muriungi>>
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //create the lcd variable

#include <NewPing.h>

//ULTRASONIC SENSOR

#define TRIGGER_PIN  31  // Arduino pin : trigger pin on the ultrasonic sensor.
#define ECHO_PIN     33  // Arduino pin : echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in cm). 
                         //Maximum sensor distance is rated at (400-500)cm.

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

//LEDS
int Green = 35;
int BlueRight = 37;
int BlueLeft = 39;
int RedRight = 41;
int RedLeft = 43;

int buzzer = 45;

// MOTORS 
/*
 * Connect L1 and L2 of the L298N
 * to the Pin 2 and 3 for Motor 1
 * Connect L3 and L4 of the L298N
 * to the Pin 4 and 5 for Motor 2
*/
int in1 = 47;
int in2 = 49;
int in3 = 51;
int in4 = 53;

//Enable Pins
int enA = 7;
int enB = 8;

//BUTTON 
const int buttonAuto = 6;
int buttonState;

 int distance;

// BLUETOOTH MODULE

char data = 0;  // Input from the bluetooth terminal from the 
                     //smartphone through the "ROBOREMO"  

void setup(){

  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(BlueLeft, OUTPUT);
  pinMode(BlueRight, OUTPUT);
  pinMode(RedLeft, OUTPUT);
  pinMode(RedRight, OUTPUT);
  pinMode(buttonAuto, INPUT);

  lcd.clear();                    //clear the LCD during setup
  lcd.begin(16,2);                //define the columns (16) and rows (2)
  lcd.setCursor(4,0);
  lcd.print("ROBO-KAM");
  lcd.setCursor(0,0);
  lcd.print("ROBOTICS - TECH");
  }

  void loop(){
      
      buttonState = digitalRead(buttonAuto);

      // This is the Code that facilitates automatic movement of the Robot
        //By the use of ultrasonic sensor to detect obstacles hence being able
        //to make decisions accordingly.
        //The other part of the code is used in controlling using 
        //bluetooth module. The movement functions are the same but the controls 
        //are different.
        //When controlling using bluetooth module, the ultrasonic sensor is deactivated 
        //to allow efficient control using bluetooth.
        
      if (buttonState == HIGH)
      {
      delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
      Serial.print("Ping: ");
      Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
      Serial.println("cm");

      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("ROBO-KAM");
      lcd.setCursor(2,1);
      lcd.print("AUTO MODE");
      
      distance = sonar.ping_cm();

      while (distance >= 2)
      {
        forwardMove();
        delay(10000);
        distance = sonar.ping_cm();
        }
        stopMove();
        delay(5000);
      }
        /*
         * Below Code with SERIAL is a bluetooth code that enable control of the 
         * Robot with the bluetooth Module.
         * The FUNCTIONS used while on Autonomous mode are the same used in 
         * Bluetooth mode to ensure effective and efficiency during control.
        */

        if(Serial.available() > 0){ //Check from the module if the data is available
          data = Serial.read(); // Obtain data from the User/Mobile phone
          Serial.print(data);        //Print Value inside data in Serial monitor
          Serial.print("\n");        //New line 
          /*
           * THERE IS REPETITION IN stop CODE BUT 
           * WITH DIFFERENT VALUE WHICH IS AS A RESULT 
           * OF USING "ROBOREMO BLUETOOTH APP"
           * IN CONTROLLING THE ROBOT.
           * EVERY STOP IS ASSIGN TO THE DIRECTION OF THE 
           * MOVEMENT WHEN THE ROBOT IS MOVING>
           * IT'S MADE ACTIVE BY SETTING THE "Release Action Value"
           * 
           * The structure of the code can be modified 
           * depending on the Application you are using the 
           * Code for. You can tweak it to suit your needs.
          */

          if(data == 'f'){
            // if the value is f, both motors are started 
            // on the clockwise or forward movement
            forwardMove();
            }
            else if(data == 's'){ //RELEASE ACTION VALUE
              //STOP
              //Stop both motors
              stopMove();
              }
              else if(data == 'b'){
                //Start both motors on reverse/backwards direction
                //Or on anticlockwise direction
                reverseMove();
                }
                else if(data == 'h'){  //RELEASE ACTION VALUE
                  //STOP
                  //Stop both motors by making their speed = 0
                  stopMove();
                  }
                  else if(data == 'l'){
                    //Robot turns LEFT
                    leftMove();
                    }
                    else if(data == '0'){  //RELEASE ACTION VALUE
                      //STOP
                      //Stop both motors by making their speed = 0
                      stopMove();
                      }
                      else if(data == 'r'){
                        //Robot turns RIGHT
                        rightMove();
                        }
                        else if(data == 'z'){  //RELEASE ACTION VALUE
                          //STOP
                          //Stop both motors by making their speed = 0
                          stopMove();
                          }
          }
    }


    /*
     * FUNCTIONS OF DIFFERENT STATES OF THE ROBOT 
     * There are five different states of the movement
     * Described by the foolowing functions :
     * 
     * FORWARDMOVE : Clockwise Movement
     * STOPMOVE : Stop
     * REVERSEMOVE : Anticlockwise Movement
     * LEFTMOVE : Movement on the Left-Side 
     * RIGHTMOVE : Movement on the Right-Side
     * 
    */

    
    void forwardMove(){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);  
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 200);
      analogWrite(enA, 200);
      digitalWrite(ledGreen, HIGH);

      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("ROBO-KAM");
      lcd.setCursor(1,1);
      lcd.print("MOVING FORWARD");
      }
      
    void reverseMove(){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);  
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, 200);
      analogWrite(enA, 200);;

      digitalWrite(ledRedRight, HIGH);
      digitalWrite(ledRedLeft, HIGH);
      delay(100);
      digitalWrite(ledRedRight, LOW);
      digitalWrite(ledRedLeft, LOW);

      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);

      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("ROBO-KAM");
      lcd.setCursor(1,1);
      lcd.print("MOVING REVERSE");
      }
      
    void stopMove(){
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);

      digitalWrite(ledRedRight, HIGH);
      digitalWrite(ledRedLeft, HIGH);
      delay(1000);
      digitalWrite(ledRedRight, LOW);
      digitalWrite(ledRedLeft, LOW);

      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);

      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("ROBO-KAM");
      lcd.setCursor(2,1);
      lcd.print("HAS STOPPED");
      }
      
    void leftMove(){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 200);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enB, 200);

      digitalWrite(ledBlueLeft, HIGH);
      delay(100);
      digitalWrite(ledBlueLeft, LOW);

      //digitalWrite(buzzer, HIGH);
      //delay(500);
      //digitalWrite(buzzer, LOW);

      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("ROBO-KAM");
      lcd.setCursor(0,1);
      lcd.print("MOVING LEFT-SIDE");
      }
      
    void rightMove(){
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      analogWrite(enA, 200);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 200);

      digitalWrite(ledBlueRight, HIGH);
      delay(100);
      digitalWrite(ledBlueRight, LOW);

      //digitalWrite(buzzer, HIGH);
      //delay(500);
      //digitalWrite(buzzer, LOW);

      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("ROBO-KAM");
      lcd.setCursor(1,1);
      lcd.print("MOVING RIGHTSIDE");
      }
    
     
