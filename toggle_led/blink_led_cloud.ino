// Control LED over the internet using RESTful

int led1 = D0;
int led2 = D7;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // declare a Particle function to turn LED on and off from the cloud
  Particle.function("led", ledToggle);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

}

void loop()
{

}

int ledToggle(String command)
{
  if (command=="on")
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    return 1;
  }
  else if (command=="off")
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    return 0;
  }
  else
  {
    return -1;
  }

}
