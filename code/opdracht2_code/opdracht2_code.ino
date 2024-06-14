// Een Array voor alle pins. 
int pinArray[] = {13, 12, 11, 10, 9, 8, 7, 6};

// De setup voor alle pins 
void setup(){
  for (int count = 0; count < 8; count++) { 
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop()
{
// Knipperen van alle LEDs
  blinkAll(70);
}


void blinkAll(int time) {
  // Knipper van links naar rechts 
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinArray[i], HIGH);
    delay(time);
    digitalWrite(pinArray[i], LOW);
  }
  // Knipper van rechts naar links
  for (int i = 7; i >= 0; i--) {
    digitalWrite(pinArray[i], HIGH);
    delay(time);
    digitalWrite(pinArray[i], LOW);
  }
}
