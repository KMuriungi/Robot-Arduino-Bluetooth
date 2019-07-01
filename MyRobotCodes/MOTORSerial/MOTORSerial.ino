int motorRight = 11;
int motorLeft = 12;

void setup(){
  pinMode(motorRight, OUTPUT);
  pinMode(motorLeft, OUTPUT);
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
        analogWrite(motorLeft, speed);
        analogWrite(motorRight, speed);
        }
      }
    }
