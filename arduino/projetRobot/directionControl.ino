void APP_MOTOR_DIRECTION_INIT(){
  robot.leftwhileturns = 0;
  robot.rightwhileturns = 0;
  robot.performTurn = false;
  robot.isReady = true;
  robot.isStopDone = false;
  robot.state = MOVE_STATE_INIT;
}

void APP_MOTOR_DIRECTION_TASKS(){
  switch(robot.state){
    case MOVE_STATE_INIT:
    {
      robot.state = MOVE_STATE_STOP;
      break;
    }

    case  MOVE_STATE_STOP :
    {
      Serial.print("Move state stop");
      currentMillis = millis();

      
      if(robot.isStopDone == false){
        leftMotor.state = MOTOR_STATE_RELEASE;
        rightMotor.state = MOTOR_STATE_RELEASE;
        startMillis = millis();
        robot.isStopDone = true;
      }

      else if(currentMillis - startMillis > 670){
        robot.isReady = true;
        robot.isStopDone = false;
        robot.state = MOVE_STATE_WAIT;
      }
      break;
    }
    
    
    case MOVE_STATE_TURN_LEFT :
    {
      if(robot.performTurn){
        if(robot.rightwhileturns > 23){
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
          robot.performTurn = false;
          robot.state = MOVE_STATE_STOP;
          }
      }

      else{
        Serial.println("I'm turning left");
        
        leftMotor.motorSpeed = 70;
        rightMotor.motorSpeed = 70;
  
        //leftMotor.state = MOTOR_STATE_BACKWARD;
        leftMotor.startConfigDone = false;
        rightMotor.startConfigDone = false;


        rightMotor.state = MOTOR_STATE_FORWARD;
        robot.isReady = false;
        robot.performTurn = true;
      }
      break;
    }
    
    case MOVE_STATE_TURN_RIGHT:
    {
      if(robot.performTurn){
        if(robot.leftwhileturns > 23){
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
          robot.performTurn = false;
          robot.state = MOVE_STATE_STOP;
          }
      }
      else{
        Serial.println("I'm turning right");

        leftMotor.motorSpeed = 70;  //0-->250
        rightMotor.motorSpeed = 70;
  
        leftMotor.state = MOTOR_STATE_FORWARD;
        //rightMotor.state = MOTOR_STATE_CONFIGURE;
        robot.isReady = false;
        robot.performTurn = true;
        leftMotor.startConfigDone = false;
        rightMotor.startConfigDone = false;
      }
      break;
    }

    
    case MOVE_STATE_FORWARD :
    {
      if(robot.isReady == true){
        
        Serial.println("I'm moving forward");
;
        leftMotor.motorSpeed = 120;
        rightMotor.motorSpeed = 120;
        leftMotor.startConfigDone = false;
        rightMotor.startConfigDone = false;
        leftMotor.state = MOTOR_STATE_FORWARD;
        rightMotor.state = MOTOR_STATE_FORWARD;
        robot.isReady = false;
      }
      else{
        if(robot.leftwhileturns + robot.rightwhileturns> 360 /* && robot.rightwhileturns >*/  ){
          robot.state = MOVE_STATE_STOP;
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
        }
      } 
      break;
    }
    
    case MOVE_STATE_WAIT:
    { 
      Serial.println("I'm still here");
      break;
    }
  }
}
