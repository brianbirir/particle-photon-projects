/*
 * Project photo_resistor
 * Description:
 * Author:
 * Date:
 */

int led = D0;

// Plug photoresistor side to this
int photoresistor = A0;

// connect other side photoresistor to power pin
int power = A5;

// where to store photoresistor value
int analogvalue;

// setup() runs once, when the device is first turned on.
void setup() {

  // led pin output
  pinMode(led,OUTPUT);

  // photoresistor input
  pinMode(photoresistor,INPUT);

  // output for powering photoresistor
  pinMode(power,OUTPUT);

  // write to photoresistor power pin
  digitalWrite(power,HIGH);

  // access value for photoresistor from cloud
  Particle.variable("analogvalue", &analogvalue, INT);

  // turn led on and off from the cloud
  Particle.function("led",ledToggle);


}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // check to see value of photoresistor and store it in int variable analogvalue
  analogvalue = analogRead(photoresistor);
  delay(100);
}

// led toggle function which is referenced by Particle.function() called "led"
int ledToggle(String command) {

    if (command=="on") {
        digitalWrite(led,HIGH);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(led,LOW);
        return 0;
    }
    else {
        return -1;
    }
}
