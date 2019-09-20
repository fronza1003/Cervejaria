#include <Arduino.h>

/*
  Turns on an LED on for one second, then off for one second, repeatedly.
*/

int led = 8;

void setup()
{
	Serial.begin(9600);

	// initialize the digital pin as an output.
	// Pin 13 has an LED connected on most Arduino boards:
	pinMode(led, OUTPUT);
}

void loop()
{

	delay(500);
	digitalWrite(led, HIGH);
  Serial.println("HIGH");
	delay(500);
	digitalWrite(led, LOW);
  Serial.println("LOW");
}
