
#include "libs/Arduino.h"

#include "components/SensorManager.h"
#include "components/SensorManager.cpp"

SensorManager sensorsManager;

void setup()
{
  sensorsManager.Setup();

  Serial.begin(9600); // Starts the serial communication
}
void loop()
{
  Serial.println(sensorsManager.GetStatusString());
  delay(10);
}