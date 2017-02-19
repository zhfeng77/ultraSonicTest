//Ultra sonic class library
//zhf
//2017-2-19
//modify: add minimun distance and maximum distance

#include "zhf_SR04.h"

//Instance the ultra sonic class
SR04::SR04(int trigPin,int echoPin)
{
	pinMode(trigPin, OUTPUT);	//Output trig signal to ultrasonic Trig Pin	
	pinMode(echoPin, INPUT);	//Input echo signal from ultrasonic Echo Pin
	_trigPin = trigPin;			//Save trig pin information to member variable
	_echoPin = echoPin;			//Save echo pin information to member variable


	_overRange = 0;
	//_overMaxRange = false;			// init overrange to false
	//_overMinRange = false;			// init overrange to false
}

//Send trig signal and get distance
float SR04::GetDistance()
{
	//send a 10ms positive pulse to trig TrigPin
	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trigPin, LOW);
	float distance = pulseIn(_echoPin, HIGH)/58.00;

	if(distance>450)
	{
		_overRange = 2;
	}
	else if(distance<3)
	{
		_overRange = 1;
	}
	else
	{
		_overRange = 0;
	}
	// if(distance>450)
	// {
	// 	_overMaxRange = true;	//over maximum range 450cm	    
	// }
	// else if(distance<3)
	// {
	// 	_overMinRange = true;	//over minimum range 3cm
	// }
	// else
	// {
	// 	_overMinRange = false;
	// 	_overMaxRange = false;
	// }
	return distance;
}

//Test if distance is overrange 3cm-450cm
//0-- normal   1-  over min range  2-- over max range
int SR04::IsDistanceOverRange()
{
	// boolean ret = 0;
	// if(_overMinRange)
	// {
	// 	ret = 1;
	// }
	// else if(_overMaxRange)
	// {
	// 	ret = 2;
	// }
	// else
	// {
	// 	ret = 0;
	// }
	// return ret;
	return _overRange;
}



