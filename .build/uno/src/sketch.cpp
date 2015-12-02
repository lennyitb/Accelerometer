#include <Arduino.h>

void setup ();
void loop ();
#line 1 "src/sketch.ino"
#define STARTSTOP 11
#define BROADCAST 12
#define RECORDING 13

#define XPIN A5
#define YPIN A4
#define ZPIN A3

/* Should be usefull working with INPUT_PULLUPs */
#define high LOW
#define low HIGH

/* Minimum expected reading. Subtract this from input */
#define ZERO 512

void setup ()
{
	/* Set up buttons and recording light */
	pinMode(STARTSTOP, INPUT_PULLUP);
	pinMode(BROADCAST, INPUT_PULLUP);
	pinMode(RECORDING, OUTPUT);

	Serial.begin(9600);

	analogReference(EXTERNAL);
	pinMode(XPIN, INPUT);
	pinMode(YPIN, INPUT);
	pinMode(ZPIN, INPUT);
}

void loop ()
{
	/* Read accelerometer and delay between readings
	 * output is between 0 and 254, fits into a char!*/
	char x = (analogRead(XPIN) - ZERO) / 2;
	delay(50);
	char y = (analogRead(YPIN) - ZERO) / 2;
	delay(50);
	char z = (analogRead(ZPIN) - ZERO) / 2;

}
