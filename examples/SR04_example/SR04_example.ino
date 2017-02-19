#include "zhf_SR04.h"

#define TrigPin 2
#define EchoPin 3

#define Interval 1000

SR04 ultrasonic = SR04(TrigPin,EchoPin);

float distance;

char msgOverMinRange[]="Over minimum range.";
char msgOverMaxRange[]="Over maximum range.";

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	distance = ultrasonic.GetDistance();
	int ret = ultrasonic.IsDistanceOverRange();
	Serial.print(ret);
	if(1==ret)
	{
		Serial.println(msgOverMinRange);    
	}
	else if(2==ret)
	{
		Serial.println(msgOverMaxRange);
	}
	Serial.print(distance);
	Serial.println("cm");
	delay(Interval)	;
}