//int motorRightForward = 11;
int motorRightReverse = 5;
//int motorLeftForward = 12;
int motorLeftReverse = 6;

void setup(){
//  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightReverse, OUTPUT);
  //pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftReverse, OUTPUT);
  Serial.begin(9600);
  while(! Serial);
  Serial.println("Speed 0 to 255");
  }

  void loop(){
    if (Serial.available())
    {
      int speed = Serial.parseInt();
      if (speed >= 0 && speed <= 255)
      {
        //analogWrite(motorLeftForward, speed);
        analogWrite(motorLeftReverse, speed);
        //analogWrite(motorRightForward, speed);
        analogWrite(motorRightReverse, speed);
        }
      }
    }
