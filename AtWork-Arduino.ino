#include "libs/Arduino.h"

#include "components/SensorManager.h"
#include "components/SensorManager.cpp"

#include "DriveConfig.h"

BasicStepperDriver stepperRight(MOTOR_STEPS, DIR_RIGHT, STEP_RIGHT);
BasicStepperDriver stepperLeft(MOTOR_STEPS, DIR_LEFT, STEP_LEFT);

SyncDriver controller(stepperLeft, stepperRight);

SensorManager sensorsManager;

int td = 35;
int error = 0;
String s = "", s1, s2, s3;
// Final heading hard coded
/*
 *  0   -> N
 *  90  -> E
 *  180 -> S
 *  270 -> W
 */
int fin_heading = 0, curr_heading;
int m11 = 3, m12 = 4, m21 = 5, m22 = 6;
// Global variables
int t = 2, e = 7; // HCSR04 control pins
int d, dt;        // Distance calculated
// int servoPin=9;
int trans[1000], count = 0;
int dis1, dis2, dis3;

void setup()
{
  Serial.begin(9600);

  sensorsManager.Setup();
  stepperRight.begin(MOTOR_RIGHT_RPM, MICROSTEPS);
  stepperLeft.begin(MOTOR_LEFT_RPM, MICROSTEPS);
}
// void loop() {
//   Serial.println(sensorsManager.GetStatusString());
//   forward();
//   delay(1000);
//   right();
//   delay(1000);
//   left();
//   delay(1000);
//   Rotate180();
// }

void loop()
{
  String sc = "+";
  heading();
  distance();
  s1 = String(dis1);
  s2 = String(dis2);
  s3 = String(dis3);
  String head = String((int)curr_heading);
  // String head="360";
  s = sc + s1 + sc + s2 + sc + s3 + sc + head + "arg";
  Serial.print(s);
  Serial.println();
  // Algorithm
  char cd = 'f';
  cd = dist_empty();
  switch (cd)
  {

  case 'l':
    left();
    delay(420);
    stop();
    delay(100);
    break;
  case 'r':
    right();
    delay(420);
    stop();
    delay(100);
    break;
  case 'f':
    forward();
    delay(150);
    stop();
    delay(100);
    break;
  default:
    stop();
  }
  Serial.println(cd);
  delay(100);
}
char dist_empty()
{
  // Follow RHR
  td = 18;
  if (dis1 < td && dis1 != 0)
  {
    if (dis2 > td || dis2 == 0)
      return 'l';
    else if (dis3 > td || dis3 == 0)
      return 'r';
    else
      return 's';
  }
  else
  {
    /*if(dis3<=10)
    return 'l';//a=l
    else if(dis2<=10)
    return 'r';//b=r
    else*/
    return 'f';
  }
}

// Distance acquire
void distance()
{
  float *distances = sensorsManager.GetDistances();
  if (distances[0] < distances[1])
    dis1 = distances[0];
  else
    dis1 = distances[1];

  dis2 = distances[3];
  dis3 = distances[4];
}

void heading()
{
  curr_heading = (int)sensorsManager.GetHeading();
}

void right()
{
  controller.rotate(-300, -300);
}

void left()
{
  controller.rotate(300, 300);
}

void Rotate180()
{
  controller.rotate(360, 360);
}

void forward()
{
  controller.rotate(100, -100);
}

void stop()
{
  controller.startBrake();
}