#include <LiquidCrystal.h>

#include <NewPing.h>

#define TRIGGER_PIN  26  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     24  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

LiquidCrystal lcd(11, NULL, 12, 7, 8, 9, 10); //create the lcd variable

int ledG1 = 46;
int ledG2 = 42;
int ledY1 = 44;
int ledY2 = 30;
int ledR1 = 48;
int ledR2 = 28;
int buzzer = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  
  lcd.clear();                    //clear the LCD during setup
  lcd.begin(20,4);                //define the columns (16) and rows (2)

  pinMode(ledG1, OUTPUT);
  pinMode(ledG2, OUTPUT);
  pinMode(ledY1, OUTPUT);
  pinMode(ledY2, OUTPUT);
  pinMode(ledR1, OUTPUT);
  pinMode(ledR2, OUTPUT);
  pinMode(buzzer, OUTPUT);


  digitalWrite(ledG1, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GREEN ON");
  delay(500);
  digitalWrite(ledG1, LOW);
  digitalWrite(ledG2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GREEN ON");
  delay(500);
  digitalWrite(ledG2, LOW);
  digitalWrite(ledY1, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("YELLOW ON");
  delay(500);
  digitalWrite(ledY1, LOW);
  digitalWrite(ledY2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("YELLOW ON");
  delay(500);
  digitalWrite(ledY2, LOW);
  digitalWrite(ledR1, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RED ON");
  delay(500);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledR2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RED ON");
  delay(500);
  digitalWrite(ledR2, LOW);
  delay(500);
  digitalWrite(ledG1, HIGH);
  digitalWrite(ledG2, HIGH);
  digitalWrite(ledY1, HIGH);
  digitalWrite(ledY2, HIGH);
  digitalWrite(ledR1, HIGH);
  digitalWrite(ledR2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ALL LIGHTS ON");
  delay(1000);
  digitalWrite(ledG1, LOW);
  digitalWrite(ledG2, LOW);
  digitalWrite(ledY1, LOW);
  digitalWrite(ledY2, LOW);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledR2, LOW);

  digitalWrite(ledG1, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GREEN ON");
  delay(500);
  digitalWrite(ledG1, LOW);
  digitalWrite(ledG1, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GREEN ON");
  delay(500);
  digitalWrite(ledG1, LOW);
  digitalWrite(ledG2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GREEN ON");
  delay(500);
  digitalWrite(ledG2, LOW);
  digitalWrite(ledG2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GREEN ON");
  delay(500);
  digitalWrite(ledG2, LOW);
  digitalWrite(ledY1, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("YELLOW ON");
  delay(500);
  digitalWrite(ledY1, LOW);
  digitalWrite(ledY1, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("YELLOW ON");
  delay(500);
  digitalWrite(ledY1, LOW);
  digitalWrite(ledY2, HIGH);
  delay(500);
  digitalWrite(ledY2, LOW);
  digitalWrite(ledY2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("YELLOW ON");
  delay(500);
  digitalWrite(ledY2, LOW);
  digitalWrite(ledR1, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RED ON");
  delay(500);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledR1, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RED ON");
  delay(500);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledR2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RED ON");
  delay(500);
  digitalWrite(ledR2, LOW);
  digitalWrite(ledR2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RED ON");
  delay(500);
  digitalWrite(ledR2, LOW);
  delay(500);
  digitalWrite(ledG1, HIGH);
  digitalWrite(ledG2, HIGH);
  digitalWrite(ledY1, HIGH);
  digitalWrite(ledY2, HIGH);
  digitalWrite(ledR1, HIGH);
  digitalWrite(ledR2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ALL LIGHTS ON");
  delay(500);
  digitalWrite(ledG1, LOW);
  digitalWrite(ledG2, LOW);
  digitalWrite(ledY1, LOW);
  digitalWrite(ledY2, LOW);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledR2, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ALL LIGHTS OFF");
  delay(500);
  digitalWrite(ledG1, HIGH);
  digitalWrite(ledG2, HIGH);
  digitalWrite(ledY1, HIGH);
  digitalWrite(ledY2, HIGH);
  digitalWrite(ledR1, HIGH);
  digitalWrite(ledR2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ALL LIGHTS ON");
  delay(500);
  digitalWrite(ledG1, LOW);
  digitalWrite(ledG2, LOW);
  digitalWrite(ledY1, LOW);
  digitalWrite(ledY2, LOW);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledR2, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ALL LIGHTS OFF");
  delay(500);
  digitalWrite(ledG1, HIGH);
  digitalWrite(ledG2, HIGH);
  digitalWrite(ledY1, HIGH);
  digitalWrite(ledY2, HIGH);
  digitalWrite(ledR1, HIGH);
  digitalWrite(ledR2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ALL LIGHTS ON");
  delay(500);
  digitalWrite(ledG1, LOW);
  digitalWrite(ledG2, LOW);
  digitalWrite(ledY1, LOW);
  digitalWrite(ledY2, LOW);
  digitalWrite(ledR1, LOW);
  digitalWrite(ledR2, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ALL LIGHTS OFF");
  delay(100);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  if (sonar.ping_cm() == 1) {
    digitalWrite(ledR1, HIGH);
    digitalWrite(ledR2, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OBJECTS DETECTED");
    
  } 

  delay(500);
}
