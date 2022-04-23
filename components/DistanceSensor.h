#ifndef DistanceSensor_h
#define DistanceSensor_h

#include "../libs/SRF05/SRF05.h"
#include "../libs/SRF05/SRF05.cpp"

#define SENSOR_COUNT 5

const int TRIG1 = 31;
const int ECHO1 = 30;
const int TRIG2 = 35;
const int ECHO2 = 34;
const int TRIG3 = 39;
const int ECHO3 = 38;
const int TRIG4 = 43;
const int ECHO4 = 42;
const int TRIG5 = 47;
const int ECHO5 = 46;

class DistanceSensor
{
public:
    void Setup();
    void GetDistances(float * distances);
    String GetDistancesString();

    struct SensorsStruct
    {
        SRF05 S1;
        SRF05 S2;
        SRF05 S3;
        SRF05 S4;
        SRF05 S5;
    };

    SensorsStruct Sensors;

protected:
    int calculateDistance(byte trig, byte echo);
};

#endif