#include <LiquidCrystal.h>
 
LiquidCrystal lcd(11, NULL, 12, 7, 8, 9, 10); //create the lcd variable

char phoneInput;
int greenLed = 46;
int redLed = 48;
int yellowLed = 30;

void setup() {

  Serial.begin(9600);

  lcd.clear();                    //clear the LCD during setup
  lcd.begin(16,2);                //define the columns (16) and rows (2)
  
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);

}

void loop() {
  if(phoneInput == "G"){
    digitalWrite(greenLed, HIGH);
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("GREEN ON");
    delay(5000);
    digitalWrite(greenLed, LOW);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
    }
    
    else if(phoneInput == "R"){
      digitalWrite(redLed, HIGH);
      lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("RED ON");
    delay(5000);
    digitalWrite(redLed, LOW);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
      }
    
      else if(phoneInput == "Y"){
      digitalWrite(yellowLed, HIGH);
      lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("YELLOW ON");
    delay(5000);
    digitalWrite(yellowLed, LOW);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
      }
      
      else if(phoneInput == "0G"){
      digitalWrite(yellowLed, LOW);
      lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
      }
      
      else if(phoneInput == "0R"){
      digitalWrite(yellowLed, LOW);
      lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
      }
      
      else if(phoneInput == "0Y"){
      digitalWrite(yellowLed, LOW);
      lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
      }
      
      else if(phoneInput == "1"){
        //switch all lights ON
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, HIGH);
      digitalWrite(yellowLed, HIGH);
      lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("ALL LIGHTS ON");
      }
      
      else if(phoneInput == "0"){
        //switch all lightsOFF
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, LOW);
      lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
      }
delay(100);
}
