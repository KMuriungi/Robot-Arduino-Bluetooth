#define E1 34  // Enable Pin for motor 1
#define E2 36  // Enable Pin for motor 2

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

    digitalWrite(E1, HIGH);
    digitalWrite(E2, HIGH);

    digitalWrite(motorLeftA, HIGH);
    digitalWrite(motorLeftB, LOW);
    digitalWrite(motorRightA, HIGH);
    digitalWrite(motorRightB, LOW);

    delay(500);

    // change direction

    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);

    delay(500);

    digitalWrite(E1, HIGH);
    digitalWrite(E2, HIGH);

    digitalWrite(motorLeftA, LOW);
    digitalWrite(motorLeftB, HIGH);
    digitalWrite(motorRightA, LOW);
    digitalWrite(motorRightB, HIGH);

    delay(500);
}
