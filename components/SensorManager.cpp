#include "SensorManager.h"

inline void SensorManager::Setup()
{
    Wire.begin();

    float correctionFactor = 1.035;
    int medianParam = 7;

    Sensors.SRF1 = SRF05(TRIG1, ECHO1);
    Sensors.SRF2 = SRF05(TRIG2, ECHO2);
    Sensors.SRF3 = SRF05(TRIG3, ECHO3);
    Sensors.SRF4 = SRF05(TRIG4, ECHO4);
    Sensors.SRF5 = SRF05(TRIG5, ECHO5);
    Sensors.SRF2.setCorrectionFactor(correctionFactor);
    Sensors.SRF2.setModeMedian(medianParam);
    Sensors.SRF2.setCorrectionFactor(correctionFactor);
    Sensors.SRF2.setModeMedian(medianParam);
    Sensors.SRF3.setCorrectionFactor(correctionFactor);
    Sensors.SRF3.setModeMedian(medianParam);
    Sensors.SRF4.setCorrectionFactor(correctionFactor);
    Sensors.SRF4.setModeMedian(medianParam);
    Sensors.SRF5.setCorrectionFactor(correctionFactor);
    Sensors.SRF5.setModeMedian(medianParam);

    Sensors.Compass.init();
    Sensors.Compass.setSamplingRate(50);
}

inline void SensorManager::GetStatus(float *status)
{
    float distance1 = Sensors.SRF1.getCentimeter();
    float distance2 = Sensors.SRF2.getCentimeter();
    float distance3 = Sensors.SRF3.getCentimeter();
    float distance4 = Sensors.SRF4.getCentimeter();
    float distance5 = Sensors.SRF5.getCentimeter();
    float heading = Sensors.Compass.readHeading();

    float i[6] = {distance1, distance2, distance3, distance4, distance5, heading};
    status = i;
}

inline float* SensorManager::GetDistances()
{
    float * distances = new float[5];
    distances[0] = Sensors.SRF1.getCentimeter();
    distances[1] = Sensors.SRF2.getCentimeter();
    distances[2] = Sensors.SRF3.getCentimeter();
    distances[3] = Sensors.SRF4.getCentimeter();
    distances[4] = Sensors.SRF5.getCentimeter();

    return distances;
}

inline float SensorManager::GetHeading()
{
    float heading = Sensors.Compass.readHeading();
    return heading;
}

inline String SensorManager::GetStatusString()
{
    float distance1 = Sensors.SRF1.getCentimeter();
    float distance2 = Sensors.SRF2.getCentimeter();
    float distance3 = Sensors.SRF3.getCentimeter();
    float distance4 = Sensors.SRF4.getCentimeter();
    float distance5 = Sensors.SRF5.getCentimeter();
    int heading = Sensors.Compass.readHeading();

    return String("SRF#1: ") + String(distance1) +
           String(" , SRF#2: ") + String(distance2) +
           String(" , SRF#3: ") + String(distance3) +
           String(" , SRF#4: ") + String(distance4) +
           String(" , SRF#5: ") + String(distance5) +
           String(" , Heading: ") + String(heading);
}