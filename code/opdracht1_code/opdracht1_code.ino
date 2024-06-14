// C++ code
//
void setup()
{
// De setup voor de pins
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000); // delay van 1 seconde
  digitalWrite(13, LOW);
  delay(1000);
  
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  delay(1000);
}