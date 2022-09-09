#include "libs/Arduino.h"

#include "components/SensorManager.h"
#include "components/SensorManager.cpp"

#include "DriveConfig.h"

BasicStepperDriver stepperRight(MOTOR_STEPS, DIR_RIGHT, STEP_RIGHT);
BasicStepperDriver stepperLeft(MOTOR_STEPS, DIR_LEFT, STEP_LEFT);


SyncDriver controller(stepperLeft, stepperRight);

SensorManager sensorsManager;

void setup() {
  Serial.begin(9600);

  sensorsManager.Setup();
  stepperRight.begin(MOTOR_RIGHT_RPM, MICROSTEPS);
  stepperLeft.begin(MOTOR_LEFT_RPM, MICROSTEPS);
}
void loop() {
  Serial.println(sensorsManager.GetStatusString());
  Forward();
  delay(1000);
  Rotate90CC();
  delay(1000);
  Rotate90CCW();
  delay(1000);
  Rotate180();
}

void Rotate90CC()
{
  controller.rotate(-180, -180);
}

void Rotate90CCW()
{
  controller.rotate(180, 180);
}

void Rotate180()
{
  controller.rotate(360, 360);
}

void Forward()
{
  controller.rotate(360, -360);
}

void Stop()
{
  controller.startBrake();
}