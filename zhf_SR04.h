#ifndef ZHF_SR04_H
#define ZHF_SR04_H
#include <Arduino.h>

// define SR04 class 

class SR04
{
public:
	SR04(int trigPin,int echoPin);
	float GetDistance();
	int IsDistanceOverRange();		//测试距离是否超范围, 0--distance is in the range
									//1 -- over min range   2-- over max range

private:
	int _trigPin;
	int _echoPin;
	float _distance;
	boolean _overMaxRange;		//是否超出测量范围 3cm-450cm
	boolean _overMinRange;		//是否超出测量范围 3cm-450cm
	int _overRange;
};


#endif

