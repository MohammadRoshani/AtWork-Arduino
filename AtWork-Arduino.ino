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
  controller.rotate(300, -300);
}