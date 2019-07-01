/* This is a 2 wheel robot bluetooth controlled 
 * robot with L298N motor driver.
 * It has Ultrasonic Sensor which can assist 
 * during automatic mode when bluetooth is not 
 * used to control
 * 
 * Saturday 4th March 2017
 * By Kithinji A. Muriungi 
 * 
*/

// MOTORS 
/*
 * Connect L1 and L2 of the L298N
 * to the Pin 2 and 3 for Motor 1
 * 
 * Connect L3 and L4 of the L298N
 * to the Pin 4 and 5 for Motor 2
*/
int motorpin1 = 2;
int motorspeed1 = 3;
int motorpin2 = 4;
int motorspeed2 = 5;

// ULTRASONIC SENSOR

#define trigPin 6
#define echoPin 7

// BLUETOOTH MODULE

char bluetoothInput;

void setup(){
  pinMode(motorpin1, OUTPUT);
  pinMode(motorspeed1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorspeed2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  }

  void loop(){
    // CODE FOR ULTRASONIC SENSOR

    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Triggering the signal from the Sensor
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //Obtaining the signal/Echo to 
    //Determine the duration taken
    duration = pulseIn(echoPin, HIGH);
    //With the formulae below distance can be obtained  
    distance = (duration / 2) / 29.1;

        if(Serial.available()){ //Check from the module if the data is available
          bluetoothInput = Serial.read(); // Obtain data from the User/Mobile phone
          /*
           * THERE IS REPETITION IN stop CODE BUT 
           * WITH DIFFERENT VALUE WHICH IS AS A RESULT 
           * OF USING "ROBOREMO BLUETOOTH APP"
           * IN CONTROLLING THE ROBOT.
           * EVERY STOP IS ASSIGN TO THE DIRECTION OF THE 
           * MOVEMENT WHEN THE ROBOT IS MOVING>
           * IT'S MADE ACTIVE BY SETTING THE "Release Action Value"
          */

          if(bluetoothInput == 'f'){
            // if the value is f, both motors are started 
            // on the clockwise or forward movement
            digitalWrite(motorpin1 , HIGH);
            analogWrite(motorspeed1 , 1);
            digitalWrite(motorpin2 , HIGH);
            analogWrite(motorspeed2 , 1);
            }
            if(bluetoothInput == 's'){
              //STOP
              //Stop both motors
              digitalWrite(motorpin1 , LOW);
              analogWrite(motorspeed1, 0);
              digitalWrite(motorpin2 , LOW);
              analogWrite(motorspeed2, 0);
              }
              if(bluetoothInput == 'b'){
                //Start both motors on reverse/backwards direction
                //Or on anticlockwise direction
                digitalWrite(motorpin1 , LOW);
                analogWrite(motorspeed1 , 220);
                digitalWrite(motorpin2 , LOW);
                analogWrite(motorspeed2 , 220);
                }
                if(bluetoothInput == 'h'){
                  //STOP
                  //Stop both motors by making their speed = 0
                  digitalWrite(motorpin1 , LOW);
                  analogWrite(motorspeed1 , 0);
                  digitalWrite(motorpin2 , LOW);
                  analogWrite(motorspeed2 , 0);
                  }
                  if(bluetoothInput == 'l'){
                    //Robot turns LEFT
                    digitalWrite(motorpin1 , HIGH);
                    analogWrite(motorspeed1 , 1);
                    
                    digitalWrite(motorpin2 , LOW);
                    analogWrite(motorspeed2 , 220);
                    }
                    if(bluetoothInput == '0'){
                      //STOP
                      //Stop both motors by making their speed = 0
                      digitalWrite(motorpin1 , LOW);
                      analogWrite(motorspeed1 , 0);
                      digitalWrite(motorpin2 , LOW);
                      analogWrite(motorspeed2 , 0);
                      }
                      if(bluetoothInput == 'r'){
                        //Robot turns RIGHT
                        digitalWrite(motorpin1 , LOW);
                        analogWrite(motorspeed1 , 220);
                    
                        digitalWrite(motorpin2 , HIGH);
                        analogWrite(motorspeed2 , 1);
                        }
                        if(bluetoothInput == 'z'){
                          //STOP
                          //Stop both motors by making their speed = 0
                          digitalWrite(motorpin1 , LOW);
                          analogWrite(motorspeed1 , 0);
                          
                          digitalWrite(motorpin2 , LOW);
                          analogWrite(motorspeed2 , 0);
                          }
          }
    }
