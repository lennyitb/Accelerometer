const int xpin = A5;
const int ypin = A4;
const int zpin = A3;

/* Added by LHPIV as part of button interface */
bool serialon = 0 ;

/* number of milliseconds between readings */
int sampleDelay = 50;

struct table
{
	int time;
	char x;
}

void setup()
{
	/* initialize the serial communications: */
	Serial.begin(9600);

	/* Make sure the analog-to-digital converter takes its reference voltage from
	 * the AREF pin */
	analogReference(EXTERNAL);

	pinMode(xpin, INPUT);
	pinMode(ypin, INPUT);
	pinMode(zpin, INPUT);
	/* Added by LHPIV */
	pinMode(8, INPUT_PULLUP);
}

void loop()
{
	int x = analogRead(xpin);

	/* add a small delay between pin readings.  I read that you should
	 * do this but haven't tested the importance */
	delay(50);

	int y = analogRead(ypin);

	/* add a small delay between pin readings.  I read that you should
	 * do this but haven't tested the importance */
	delay(50);

	int z = analogRead(zpin);

	/* zero_G is the reading we expect from the sensor when it detects
	 * no acceleration.  Subtract this value from the sensor reading to
	 * get a shifted sensor reading. */
	float zero_G = 512.0;
	/* scale is the number of units we expect the sensor reading to
	 * change when the acceleration along an axis changes by 1G.
	 * Divide the shifted sensor reading by scale to get acceleration in Gs. */
	float scale = 102.3;

	/* Added by LHPIV as part of button interface */
	/* int i; for (i=1;i<=50;i++) */
	/* { */
	/* 	if (digitalRead(8)==LOW) */
	/* 	/1* Pin 8 is configured as INPUT_PULLUP, */
	/* 	 *  Pressing the button pulls 8 from 5V to GND */
	/* 	 *  Therefore, logic is inverted. LOW now means */
	/* 	 *  the button IS pressed, and HIGH means it is */
	/* 	 *  not. -LHYIV*/
	/* 	{ */
	/* 		if (serialon==0) */
	/* 		{ */
	/* 			serialon=1; */
	/* 		} else { */
	/* 			serialon=0; */
	/* 		} */
	/* 		delay(1000); */
	/* 	} */
	/* 	delay(1); */
	/* } */
	/* if (serialon==1) */
	/* { */
	/* 	Serial.print(((float)x - zero_G)/scale); */
	/* 	Serial.print("\t"); */
	/* 	Serial.print(((float)y - zero_G)/scale); */
	/* 	Serial.print("\t"); */
	/* 	Serial.print(((float)z - zero_G)/scale); */
	/* 	Serial.print("\n"); */
	/* } */
}
