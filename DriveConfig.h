#ifndef DRIVE_CONFIG_H
#define DRIVE_CONFIG_H


#include "libs/StepperDriver/BasicStepperDriver.h"
#include "libs/StepperDriver/BasicStepperDriver.cpp"

#include "libs/StepperDriver/MultiDriver.h"
#include "libs/StepperDriver/MultiDriver.cpp"

#include "libs/StepperDriver/SyncDriver.h"
#include "libs/StepperDriver/SyncDriver.cpp"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define MOTOR_RIGHT_RPM 20
#define MOTOR_LEFT_RPM 20

// Right motor
#define DIR_RIGHT 17
#define STEP_RIGHT 16

// Left motor
#define DIR_LEFT 15
#define STEP_LEFT 14

// If microstepping is set externally, make sure this matches the selected mode
// 1=full step, 2=half step etc.
#define MICROSTEPS 1

#endif