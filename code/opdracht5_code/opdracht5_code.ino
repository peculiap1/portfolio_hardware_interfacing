#include <Servo.h>

Servo customServo; // Maak een servo-object aan

const int buttonPinA = 2; // Knop A aangesloten op pin 2
const int buttonPinB = 3; // Knop B aangesloten op pin 3
const int servoControlPin = 9; // Servo aangesloten op pin 9

void setup() {
  pinMode(buttonPinA, INPUT_PULLUP); // Stel knop A in als input met interne pull-up weerstand
  pinMode(buttonPinB, INPUT_PULLUP); // Stel knop B in als input met interne pull-up weerstand
  customServo.attach(servoControlPin); // Koppel de servo aan pin 9
  customServo.write(0); // Initialiseer de servo positie op 0°

  Serial.begin(9600); // Initialiseer seriële communicatie voor debugging
}

void loop() {
  bool isButtonAPressed = digitalRead(buttonPinA) == LOW; // Lees de status van knop A
  bool isButtonBPressed = digitalRead(buttonPinB) == LOW; // Lees de status van knop B

  Serial.print("Knop A: ");
  Serial.print(isButtonAPressed);
  Serial.print(" Knop B: ");
  Serial.println(isButtonBPressed);

  if (isButtonAPressed && isButtonBPressed) {
    // Beide knoppen zijn ingedrukt
    Serial.println("Beide knoppen ingedrukt");
    performServoMovement(120, 3000); // Beweeg naar 120° in 3 seconden
    delay(5000); // Blijf 5 seconden op 120°
    performServoMovement(0, 500); // Beweeg terug naar 0° in 0,5 seconden
  } else if (isButtonAPressed) {
    // Alleen knop A is ingedrukt
    Serial.println("Knop A ingedrukt");
    performServoMovement(120, 3000); // Beweeg naar 120° in 3 seconden
    performServoMovement(0, 3000); // Beweeg terug naar 0° in 3 seconden
  } else if (isButtonBPressed) {
    // Alleen knop B is ingedrukt
    Serial.println("Knop B ingedrukt");
    performServoMovement(120, 500); // Beweeg naar 120° in 0,5 seconden
    performServoMovement(0, 500); // Beweeg terug naar 0° in 0,5 seconden
  }

  delay(100); // Kleine vertraging om te debouncen
}

void performServoMovement(int targetAngle, int movementDuration) {
  int currentServoAngle = customServo.read(); // Haal de huidige hoek op
  int angleSteps = abs(currentServoAngle - targetAngle); // Bereken het aantal stappen
  int delayPerStep = movementDuration / angleSteps; // Bereken de vertraging per stap

  if (currentServoAngle < targetAngle) {
    for (int position = currentServoAngle; position <= targetAngle; position++) {
      customServo.write(position);
      delay(delayPerStep);
    }
  } else {
    for (int position = currentServoAngle; position >= targetAngle; position--) {
      customServo.write(position);
      delay(delayPerStep);
    }
  }
}
