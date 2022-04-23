#ifndef SensorManager_h
#define SensorManager_h

#include "../libs/Wire.h"

#include "../libs/SRF05/SRF05.h"
#include "../libs/SRF05/SRF05.cpp"

#include "../libs/QMC5883L/QMC5883L.h"
#include "../libs/QMC5883L/QMC5883L.cpp"

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

class SensorManager
{
public:
    void Setup();
    void GetStatus(float *status);
    String GetStatusString();

    struct SensorsStruct
    {
        SRF05 SRF1;
        SRF05 SRF2;
        SRF05 SRF3;
        SRF05 SRF4;
        SRF05 SRF5;
        QMC5883L Compass;
    };

    SensorsStruct Sensors;
};

#endif