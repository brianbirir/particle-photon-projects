// ---------
// Blink an LED
// ---------

// This program blinks an LED on and off
// D0 and D7

// assign GPIO pins
int led1 = D0;
int led2 = D7;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {

  // turn on LED
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);

  // wait for one second
  delay(1000);

  // turn off LED
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  // wait for one seconf
  delay(1000);
}
