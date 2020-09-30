
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "TimerOne.h"


//SPEED CONTROL

int counterLM = 0;
int counterRM = 0;


// MOTORS CONTROL

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *LM = AFMS.getMotor(4); 
Adafruit_DCMotor *RM = AFMS.getMotor(3);


typedef enum{
  MOTOR_STATE_INIT,
  MOTOR_STATE_CONFIGURE,
  MOTOR_STATE_WAIT
}MOTOR_STATES;

typedef enum{
  RUN_FORWARD,
  RUN_BACKWARD,
  RUN_RELEASE
}MOTOR_RUN;

typedef struct{
  MOTOR_STATES state;
  int motorSpeed;
  MOTOR_RUN runConfig;
}MOTOR_DATA;

MOTOR_DATA leftMotor;
MOTOR_DATA rightMotor;
