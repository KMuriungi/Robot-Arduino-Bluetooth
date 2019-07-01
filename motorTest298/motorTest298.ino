int motor1spin = 4;
int motor1speed = 5;

void setup(){
  pinMode(motor1spin, OUTPUT);
  pinMode(motor1speed, OUTPUT);
  }

void loop(){
  int value;

  for (value = 0; value <= 255; value+=1){
    digitalWrite(motor1spin, HIGH);
    digitalWrite(motor1speed, value);
    delay(30);
    }

    for (value = 0; value <=255; value+=1){
      digitalWrite(motor1spin, LOW);
      digitalWrite(motor1speed, value);
      delay(30);
      }
  }
