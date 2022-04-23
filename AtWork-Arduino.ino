
#include "libs/Arduino.h"

#include "libs/Wire.h"
#include "libs/HMC5883L_Simple/HMC5883L_Simple.cpp"
#include "libs/HMC5883L_Simple/HMC5883L_Simple.h"
#include "components/DistanceSensor.h"
#include "components/DistanceSensor.cpp"

HMC5883L_Simple Compass;
DistanceSensor MyDistanceSensor;

void setup()
{
  MyDistanceSensor.Setup();

  Serial.begin(9600); // Starts the serial communication
  Wire.begin();

  Compass.SetScale(COMPASS_SCALE_130);
  Compass.SetOrientation(COMPASS_HORIZONTAL_X_NORTH);
}
void loop()
{
  float heading = Compass.GetHeadingDegrees();

  Serial.println(MyDistanceSensor.GetDistancesString()+ ", Heading: "+heading);
  delay(10);
}