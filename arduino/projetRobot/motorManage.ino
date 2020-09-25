
void APP_LEFT_MOTOR_INITIALIZE(){
  leftMotor.motorSpeed = 150;
  leftMotor.state = MOTOR_STATE_INIT;
  leftMotor.runConfig = RUN_FORWARD; 
}
void APP_RIGHT_MOTOR_INITIALIZE(){
  rightMotor.motorSpeed = 150;
  rightMotor.state = MOTOR_STATE_INIT;
  rightMotor.runConfig = RUN_FORWARD; 
}

void leftMotorRun(){
  switch(leftMotor.runConfig){
    case RUN_FORWARD :
      LM->run(FORWARD);
      break;
    case RUN_BACKWARD :
      LM->run(BACKWARD);
      break;
    case RUN_RELEASE :
      LM->run(RELEASE);
      break;
  }
}

void rightMotorRun(){
  switch(leftMotor.runConfig){
    case RUN_FORWARD :
      RM->run(FORWARD);
      break;
    case RUN_BACKWARD :
      RM->run(BACKWARD);
      break;
    case RUN_RELEASE :
      RM->run(RELEASE);
      break;
  }
}


void APP_LEFT_MOTOR_TASKS(){
  switch(leftMotor.state){
    case MOTOR_STATE_INIT :
    {
      LM->setSpeed(leftMotor.motorSpeed);
      leftMotor.state = MOTOR_STATE_WAIT;
      leftMotorRun();
      break;
    }
    case MOTOR_STATE_WAIT :
    {
      break;
    }
    case MOTOR_STATE_CONFIGURE :
      Serial.print("STATE CONFIGURE");
      LM->setSpeed(leftMotor.motorSpeed);
      leftMotor.state = MOTOR_STATE_WAIT;
      leftMotorRun();
      break;
  }
}



void APP_RIGHT_MOTOR_TASKS(){
  switch(rightMotor.state){
    case MOTOR_STATE_INIT :
    {
      RM->setSpeed(rightMotor.motorSpeed);
      rightMotor.state = MOTOR_STATE_WAIT;
      rightMotorRun();
      break;
    }
    case MOTOR_STATE_WAIT :
    {
      break;
    }
    case MOTOR_STATE_CONFIGURE :
      RM->setSpeed(rightMotor.motorSpeed);
      rightMotor.state = MOTOR_STATE_WAIT;
      rightMotorRun();
      break;
  }
}
