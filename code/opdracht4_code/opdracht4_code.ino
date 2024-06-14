const int potPin = A5; // Potmeter op A5
const int ledPins[] = {2, 3, 4, 5, 6, 7}; // LED pin nummers 
const int numLeds = 6; // Aantal LEDS

void setup() {
  // Initialiseren van de LEDs als OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.begin(9600); // Initialiseer seriële communicatie voor debugging
}

void loop() {
  int potValue = analogRead(potPin); // Uitlezen van de potmeterwaarde (0-1023)
  int numLedsOn = map(potValue, 0, 1023, numLeds, 0); // Wijs de waarde toe aan het aantal LED's

  // Juiste aantal LED's inschaklen 
  for (int i = 0; i < numLeds; i++) {
    if (i < numLedsOn) {
      digitalWrite(ledPins[i], HIGH); // LED aanzetten
    } else {
      digitalWrite(ledPins[i], LOW); // LED uitzetten
    }
  }

  // Debuggen Serial Monitor 
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" -> LEDs On: ");
  Serial.println(numLedsOn);

  //Kleine delay
  delay(100);
}