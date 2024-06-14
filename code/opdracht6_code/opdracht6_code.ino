#include <Servo.h>

const int trigPin = 8;
const int echoPin = 7;
const int servoControlPin = 9;

Servo controlServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  controlServo.attach(servoControlPin);
  controlServo.write(0); // Initialiseer de servo positie op 0°

  Serial.begin(9600); // Initialiseer seriële communicatie voor debugging
}

void loop() {
  // Stuur een 10us puls om de sensor te triggeren
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lees de echo pin en bereken afstand
  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.034) / 2;

  Serial.print("Afstand: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Bereken de servo hoek op basis van de afstand
  int angle;
  if (distance <= 4) {
    angle = 0; // Object is op 4 cm, servo op 0°
  } else if (distance <= 10) {
    angle = map(distance, 4, 10, 180, 0); // Bereken de hoek op basis van de afstand
  } else {
    angle = 0; // Object is niet binnen bereik, servo op 0°
  }

  controlServo.write(angle); // Beweeg de servo naar de berekende hoek

  delay(100); // Vertraging voor stabiliteit van de sensor
}
