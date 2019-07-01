#include <LiquidCrystal.h>
 
LiquidCrystal lcd(11, NULL, 12, 7, 8, 9, 10); //create the lcd variable

int greenLed = 46;
int redLed = 48;
int redLed2 = 28;
int yellowLed = 30;
int yellowLed2 = 44;
int buzzer = 50;

void setup() {

  Serial.begin(9600);

  lcd.clear();                    //clear the LCD during setup
  lcd.begin(16,2);                //define the columns (16) and rows (2)
  
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(yellowLed2, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {

    digitalWrite(greenLed, HIGH);
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("GREEN ON");
    delay(500);
    digitalWrite(greenLed, LOW);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
    delay(500);
      digitalWrite(redLed, HIGH);
      digitalWrite(redLed2, HIGH);
      lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("RED ON");
    digitalWrite(buzzer, HIGH);
    delay(500);
    
    digitalWrite(redLed, LOW);
    digitalWrite(redLed2, LOW);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
    digitalWrite(buzzer, LOW);
      delay(500);
      
      digitalWrite(yellowLed, HIGH);
      digitalWrite(yellowLed2, HIGH);
      lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("YELLOW ON");
    delay(500);
    digitalWrite(yellowLed, LOW);
    digitalWrite(yellowLed2, LOW);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
      delay(500);
        //switch all lights ON
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, HIGH);
      digitalWrite(redLed2, HIGH);
      digitalWrite(yellowLed, HIGH);
      digitalWrite(yellowLed2, HIGH);
      lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("ALL LIGHTS ON");
      delay(1000);
        //switch all lightsOFF
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, LOW);
      digitalWrite(redLed2, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(yellowLed2, LOW);
      lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ALL LIGHTS OFF");
      
delay(100);
}
