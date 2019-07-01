#define E1 33  // Enable Pin for motor 1
#define E2 34  // Enable Pin for motor 2

#define motorLeftA 2  // Control pin 1 for motor 1
#define motorLeftB 3  // Control pin 2 for motor 1
#define motorRightA 4  // Control pin 1 for motor 2
#define motorRightB 5  // Control pin 2 for motor 2

void setup() {

    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);

    pinMode(motorLeftA, OUTPUT);
    pinMode(motorLeftB, OUTPUT);
    pinMode(motorRightA, OUTPUT);
    pinMode(motorRightB, OUTPUT);
}

void loop() {

    analogWrite(E1, 153); // Run in half speed
    analogWrite(E2, 255); // Run in full speed
    
    digitalWrite(motorLeftA, HIGH);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, HIGH);
    digitalWrite(motorRightB, LOW);

    delay(500);

    // change direction

    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);

    delay(100);

    analogWrite(E1, 255);  // Run in full speed
    analogWrite(E2, 153);  // Run in half speed

    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, HIGH);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, HIGH);

    delay(500);
}
