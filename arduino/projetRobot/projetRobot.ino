
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "TimerOne.h"

unsigned long startMillis;
unsigned long currentMillis;

//SPEED CONTROL
int counterLM = 0;
int counterRM = 0;


// MOTORS CONTROL
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *LM = AFMS.getMotor(1); 
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

typedef enum{
  MOVE_STATE_INIT,
  MOVE_STATE_TURN_LEFT,
  MOVE_STATE_TURN_RIGHT,
  MOVE_STATE_FORWARD,
  MOVE_STATE_STOP,
  MOVE_STATE_BACKWARD,
  MOVE_STATE_WAIT
}MOVE_STATES;

typedef struct{
  MOVE_STATES state;
  unsigned long int leftwhileturns;
  unsigned long int rightwhileturns;
  bool performTurn;
  bool isReady;
}ROBOT;

ROBOT robot;

typedef enum{
  SERIAL_STATE_INIT = -1,
  SERIAL_STATE_TURN_LEFT = 3,
  SERIAL_STATE_TURN_RIGHT = 1,
  SERIAL_STATE_FORWARD = 2,
  SERIAL_STATE_STOP = 0,
  SERIAL_STATE_BACKWARD = 4,
  SERIAL_STATE_WAIT = 5
}SERIAL_STATE;

typedef struct{
  SERIAL_STATE state;
}SERIAL_DATA;

SERIAL_DATA serial;
