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
      leftMotor.runConfig = RUN_RELEASE; 
      leftMotor.state = MOTOR_STATE_CONFIGURE;
      rightMotor.runConfig = RUN_RELEASE; 
      rightMotor.state = MOTOR_STATE_CONFIGURE;
      robot.isReady = true;
      break;
    }
    case MOVE_STATE_INIT:
    {
      robot.state = MOVE_STATE_STOP;
      break;
    }
    case MOVE_STATE_TURN_LEFT :
    {
      leftMotor.runConfig = RUN_BACKWARD;
      rightMotor.runConfig = RUN_FORWARD;
      leftMotor.motorSpeed = 40;
      rightMotor.motorSpeed = 40;

      leftMotor.state = MOTOR_STATE_CONFIGURE;
      rightMotor.state = MOTOR_STATE_CONFIGURE;

      robot.state = MOVE_STATE_WAIT;
      robot.isReady = false;
      robot.performTurn = true;
      break;
    }
    case MOVE_STATE_TURN_RIGHT:
    {
      leftMotor.runConfig = RUN_FORWARD;
      rightMotor.runConfig = RUN_BACKWARD;
      leftMotor.motorSpeed = 40;
      rightMotor.motorSpeed = 40;

      leftMotor.state = MOTOR_STATE_CONFIGURE;
      rightMotor.state = MOTOR_STATE_CONFIGURE;

      robot.state = MOVE_STATE_WAIT;
      robot.isReady = false;
      robot.performTurn = true;
      break;
    }
    case MOVE_STATE_FORWARD :
    {
      leftMotor.runConfig = RUN_FORWARD;
      rightMotor.runConfig = RUN_FORWARD;
      leftMotor.motorSpeed = 50;
      rightMotor.motorSpeed = 50;

      leftMotor.state = MOTOR_STATE_CONFIGURE;
      rightMotor.state = MOTOR_STATE_CONFIGURE;

      robot.state = MOVE_STATE_WAIT;
      robot.isReady = false;
      break;
    }
    case MOVE_STATE_WAIT:
    {
      if(robot.performTurn){
        if(robot.leftwhileturns > 10 && robot.rightwhileturns > 10){
          robot.state = MOVE_STATE_STOP;
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
          robot.performTurn = false;


        }
      }
      else{
        if(robot.leftwhileturns > 80 && robot.rightwhileturns > 80 ){
          robot.state = MOVE_STATE_STOP;
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
        }
      }
    }
  }
}
