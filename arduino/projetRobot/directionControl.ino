void APP_MOTOR_DIRECTION_INIT(){
  robot.leftwhileturns = 0;
  robot.rightwhileturns = 0;
  robot.performTurn = false;
  robot.state = MOVE_STATE_INIT;
  robot.isReady = true;
}

void APP_MOTOR_DIRECTION_TASKS(){
  switch(robot.state){
    case  MOVE_STATE_STOP :
    {
      Serial.println("Stop !");
      
      leftMotor.runConfig = RUN_RELEASE; 
      leftMotor.state = MOTOR_STATE_CONFIGURE;
      rightMotor.runConfig = RUN_RELEASE; 
      rightMotor.state = MOTOR_STATE_CONFIGURE;
      robot.isReady = true;

      robot.state = MOVE_STATE_WAIT;
      break;
    }
    case MOVE_STATE_INIT:
    {
      robot.state = MOVE_STATE_STOP;
      break;
    }
    case MOVE_STATE_TURN_LEFT :
    {
      Serial.println("I'm turning left");
      
      leftMotor.runConfig = RUN_BACKWARD;
      rightMotor.runConfig = RUN_FORWARD;
      leftMotor.motorSpeed = 60;
      rightMotor.motorSpeed = 60;

      leftMotor.state = MOTOR_STATE_CONFIGURE;
      rightMotor.state = MOTOR_STATE_CONFIGURE;

      robot.state = MOVE_STATE_WAIT;
      robot.isReady = false;
      robot.performTurn = true;
      break;
    }
    case MOVE_STATE_TURN_RIGHT:
    {
      Serial.println("I'm turning right");
      
      leftMotor.runConfig = RUN_FORWARD;
      rightMotor.runConfig = RUN_BACKWARD;
      leftMotor.motorSpeed = 60;  //0-250
      rightMotor.motorSpeed = 60;

      leftMotor.state = MOTOR_STATE_CONFIGURE;
      rightMotor.state = MOTOR_STATE_CONFIGURE;

      robot.state = MOVE_STATE_WAIT;
      robot.isReady = false;
      robot.performTurn = true;
      break;
      
    }
    case MOVE_STATE_FORWARD :
    {
      Serial.println("I'm moving forward");
      
      leftMotor.runConfig = RUN_FORWARD;
      rightMotor.runConfig = RUN_FORWARD;
      leftMotor.motorSpeed = 120;
      rightMotor.motorSpeed = 120;

      leftMotor.state = MOTOR_STATE_CONFIGURE;
      rightMotor.state = MOTOR_STATE_CONFIGURE;

      robot.state = MOVE_STATE_WAIT;
      robot.isReady = false;
      break;
    }


     case MOVE_STATE_BACKWARD :
    {
      Serial.println("I'm moving backward");

      leftMotor.runConfig = RUN_BACKWARD;
      rightMotor.runConfig = RUN_BACKWARD;
      leftMotor.motorSpeed = 120;
      rightMotor.motorSpeed = 120;

      leftMotor.state = MOTOR_STATE_CONFIGURE;
      rightMotor.state = MOTOR_STATE_CONFIGURE;

      robot.state = MOVE_STATE_WAIT;
      robot.isReady = false;
      break;
    }
    case MOVE_STATE_WAIT:
    { 
      if(robot.performTurn){
        if(robot.leftwhileturns + robot.rightwhileturns > 18){
          robot.state = MOVE_STATE_STOP;
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
          robot.performTurn = false;
        }
      }
      /*else{
        if(robot.leftwhileturns > 80 && robot.rightwhileturns > 80 ){
          robot.state = MOVE_STATE_STOP;
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
        }
      }*/
    }
  }
}
