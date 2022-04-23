#include "DistanceSensor.h"

// const int trigger1 = 31;
// const int echo2    = 30;

// SRF05 S2;

inline void DistanceSensor::Setup()
{
    Sensors.S1 = SRF05(TRIG1, ECHO1);
    Sensors.S2 = SRF05(TRIG2, ECHO2);
    Sensors.S3 = SRF05(TRIG3, ECHO3);
    Sensors.S4 = SRF05(TRIG4, ECHO4);
    Sensors.S5 = SRF05(TRIG5, ECHO5);

    float correctionFactor = 1.035;
    int medianParam = 7;

    Sensors.S2.setCorrectionFactor(correctionFactor);
    // Sensors.S2.setModeMedian(medianParam);
    Sensors.S2.setCorrectionFactor(correctionFactor);
    // Sensors.S2.setModeMedian(medianParam);
    Sensors.S3.setCorrectionFactor(correctionFactor);
    // Sensors.S3.setModeMedian(medianParam);
    Sensors.S4.setCorrectionFactor(correctionFactor);
    // Sensors.S4.setModeMedian(medianParam);
    Sensors.S5.setCorrectionFactor(correctionFactor);
    // Sensors.S5.setModeMedian(medianParam);
}

// DistanceSensor::Sensors DistanceSensor::SetSensors(){
//     Sensors ss;

//     ss.S1 = SRF05(trigger1, echo2);
//     return ss;
// }

inline void DistanceSensor::GetDistances(float *distances)
{
        float distance1 = Sensors.S1.getCentimeter();

    float distance2 = Sensors.S2.getCentimeter();
    float distance3 = Sensors.S3.getCentimeter();
    float distance4 = Sensors.S4.getCentimeter();
    float distance5 = Sensors.S5.getCentimeter();

    float i[5] = {distance1, distance2, distance3, distance4, distance5};
    distances = i;
}

inline String DistanceSensor::GetDistancesString()
{
    float distance1 = Sensors.S1.getCentimeter();
    float distance2 = Sensors.S2.getCentimeter();
    float distance3 = Sensors.S3.getCentimeter();
    float distance4 = Sensors.S4.getCentimeter();
    float distance5 = Sensors.S5.getCentimeter();

    return String("SRF#1: ")+String(distance1)+
           String(" , SRF#2: ")+String(distance2)+
           String(" , SRF#3: ")+String(distance3)+
           String(" , SRF#4: ")+String(distance4)+
           String(" , SRF#5: ")+String(distance5);
}