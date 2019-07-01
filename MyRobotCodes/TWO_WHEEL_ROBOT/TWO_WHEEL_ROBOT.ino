//by : KITHINJI A. MURIUNGI
// BLUETOOTH CONTROLLED ROBOT
//A 2-WHEELED ROBOT WITH CASTOR_WHEEL

int left_motor = 11;    // motors declaration
int right_motor = 12;

char value;

void setup()
{
  Serial.begin(9600);    //Serial communication starts
  
     //Motor Initialization as output
  pinMode(left_motor,OUTPUT);
  pinMode(right_motor,OUTPUT);
}

void loop()
{
 value=Serial.read();    //Reading serial value
 switch(value)           //Switch_case starts
{
   case'W':              //Moving Forward
   forward();
   Serial.println("Robot Moving Forward");
   break;
   
   case'S':              //Moving Backward
   backward();
   Serial.println("Robot Moving Backward");
   break;
   
   case'A':              //Moving RightSide
   right();
   Serial.println("Robot Moving Right");
   break;
   
   case'D':             //Moving LeftSide
   left();
   Serial.println("Robot Moving Left");
   break;
   
   case'X':             //Stopping Robot
   Stop();
   Serial.println("Robot Stopped");
   break;
  }

 //Left and Right motors will be operating 
 //opposite to each other to produce a 
 //smooth coordination between them 
 // e.g: when m1=LOW, m2=HIGH

}
void forward()          //Moving Forward function
{
  digitalWrite(left_motor,HIGH);
  digitalWrite(right_motor,HIGH);
}

void backward()         //Moving Backward function
{
  digitalWrite(right_motor,HIGH);
  digitalWrite(left_motor,HIGH);
}

void right()            //Moving Right function
{
  digitalWrite(left_motor,LOW);
  digitalWrite(right_motor,HIGH);
}

void left()              //Moving Left function
{
  digitalWrite(left_motor,HIGH);
  digitalWrite(right_motor,LOW);
}

void Stop()              //Moving Stop function
{
  digitalWrite(left_motor,LOW);
  digitalWrite(right_motor,LOW);
}

