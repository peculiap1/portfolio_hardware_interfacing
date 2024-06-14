const int led1 = 5; // LED 1 poort 5
const int led2 = 11; // LED 2 poort 11
const int button = 8; // Button op poort 8

int buttonState = 0; //Staat 0 als standaard
int counter = 0; // Counter 0 als standaard

void setup() {
  pinMode(led1, OUTPUT); // led 1 
  pinMode(led2, OUTPUT); // led 2
  pinMode(button, INPUT); //button
}

void loop() {
  buttonState = digitalRead(button); // De staat van de knop lezen
  if (buttonState == LOW) { // Als de staat laag/0 is 
    delay(50); // 50 delay
    counter++; // counter incrementen
    while (digitalRead(button) == LOW) { 
     
    }
    delay(50); // 50 delay

    if (counter % 2 == 0) { 
      digitalWrite(led1, LOW); // led 1 uit 
      digitalWrite(led2, HIGH); // led 2 aan
    } else {
      digitalWrite(led1, HIGH); // led 1 aan 
      digitalWrite(led2, LOW); // led 2 uit 
    }
  }
}
