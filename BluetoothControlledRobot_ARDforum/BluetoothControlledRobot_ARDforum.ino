

/*
   Project Spartacus

  This Project is a multi Functional arduino robot equipped with
  LDR, IR reciever sensor, Ultrasonic Sensor, Line Tracking Sensor,
  Bluetooth Sensor, and RF RxTx.

  created 10 Jun 2016
  modified 26 July 2016
  by Arthur Mosca

*/


#include <Ultrasonic.h>
#include <IRremote.h>

#define E1 10      // L293D Enable Pin1
#define B2 9      // L293D Enable Pin1
#define MotorLeft1  6   //Left motor1
#define MotorLeft2  7     //Left motor2
#define MotorRight1 8     //Right motor2
#define MotorRight2 11    //Right motor2   
#define DipSw1 4    
#define DipSw2 5
#define DipSw3 31
Ultrasonic ultrasonic_f(3,12);
Ultrasonic ultrasonic_r(22,23);
Ultrasonic ultrasonic_l(27,28);


//Ultrasonic
int ult_f = 0;
int ult_r = 0;
int ult_l = 0;


//IR
int receiver = 2;
IRrecv irrecv(receiver);
decode_results results;

//DIP Switch
int sDipSw1;
int sDipSw2;
int sDipSw3;
int address;


void forward()

  analogWrite(E1,150);
  analogWrite(B2,150);
  digitalWrite(MotorLeft1, HIGH);
  digitalWrite(MotorLeft2, LOW);
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorRight2, LOW);

void left()
  analogWrite(E1,80);
  analogWrite(B2,80);
  digitalWrite(MotorLeft2, HIGH);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorRight2, LOW);

void right()
  analogWrite(E1, 80);
  analogWrite(B2, 80);
  digitalWrite(MotorLeft1, HIGH);
  digitalWrite(MotorLeft2, LOW);
  digitalWrite(MotorRight2, HIGH);
  digitalWrite(MotorRight1, LOW);

void reverse()
  analogWrite(E1, 255);
  analogWrite(B2, 255);
  digitalWrite(MotorLeft2,HIGH);
  digitalWrite(MotorRight2,HIGH);
  digitalWrite(MotorLeft1,LOW);
  digitalWrite(MotorRight1,LOW);

void stop()
  analogWrite(E1, 0);
  analogWrite(B2, 0);

void setup()
{
pinMode(E1, OUTPUT);
pinMode(B2, OUTPUT);
pinMode(MotorLeft1, OUTPUT);
pinMode(MotorLeft2, OUTPUT);
pinMode(MotorRight1, OUTPUT);
pinMode(MotorRight2, OUTPUT);
pinMode(DipSw1, INPUT_PULLUP);
pinMode(DipSw2, INPUT_PULLUP);
pinMode(DipSw3, INPUT_PULLUP);
Serial.begin(9600);
delay(1);
}

void loop()
{
sDipSw1 = digitalRead (DipSw1);
sDipSw2 = digitalRead (DipSw2);
sDipSw3 = digitalRead (DipSw3); 
ult_f = (ultrasonic_f.Ranging(CM));
ult_r = (ultrasonic_r.Ranging(CM));
ult_l = (ultrasonic_l.Ranging(CM));
address = ((sDipSw1)+(sDipSw2)*2+(!sDipSw3)*4); //this portion is for addressing

//BLUETOOTH MODE
if(Serial.available())
{
switch(Serial.read())
{
case 'f':
        forward();
        break;
case 'b':
  backward();
        break;
case 'l':
        left();
        break;
case 'r':
        right();
        break;
case 's':
        stop();
        break;

}
}
//LDR, INFRARED,LINE TRACKER,ULTRASONIC
//serial monitor
Serial.println(LDRvalue1, DEC);
Serial.println(LDRvalue2, DEC);
Serial.println(LDRvalue3, DEC);
Serial.println(ult_f,DEC);
Serial.println(ult_r, DEC);
Serial.println(ult_l, DEC);
Serial.println(address, HEX);
Serial.println(results.value, HEX);
irrecv.enableIRIn();
delay (200);
Serial.println("--------------------------");


if (irrecv.decode(&results))
{
irrecv.resume();

}
//FORWARD MOVEMENT
if(LDRvalue2 <= threshold && address == 2 || results.value == 0x807FA05F && address == 3 || ult_f > 45 && ult_r > 45 && ult_l > 45 && address == 7)
{
forward();
  
}

//LEFT MOVEMENT
else if(LDRvalue3 <= threshold && address == 2 || results.value == 0x807F48B7 && address == 3 || ult_l < 35 &&  ult_l < ult_f  && address == 7)
{
left(); 

}

//RIGHT MOVEMENT
else if(LDRvalue1 <= threshold && address == 2 || results.value == 0x807F8877 && address == 3 || ult_r < 35 && ult_r < ult_f && address == 7)
{
right();
  
}

//STOP
else if(LDRvalue1 <= threshold && LDRvalue3 <= threshold && LDRvalue2 <= threshold && address == 2 || results.value == 0xFFFFFFFF && address == 3)
{
stop(); 

}

//REVERSE MOVEMENT
else if(results.value == 0x807F609F && address == 3 || ult_f < 45 && ult_r < 45 && ult_l < 45 && address == 7  )
{
reverse();
  
}


}
