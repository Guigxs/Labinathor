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
      //IL FAUT RESTER UN INSTANT DANS LE STOP.
      
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
       
       /*
        if(robot.rightwhileturns > 22){
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
          robot.performTurn = false;
          robot.state = MOVE_STATE_STOP;
          }
          
          */
      }

      else{
        //Serial.println("I'm turning left");
        //rightMotor.motorSpeed = 70;
        rightMotor.state = MOTOR_STATE_FORWARD_INIT;
        robot.isReady = false;
        robot.performTurn = true;
        robot.rightwhileturns = 0;
      }
      break;
    }
    
    case MOVE_STATE_TURN_RIGHT:
    {
      if(robot.performTurn){
        /*
        if(robot.leftwhileturns > 21){
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
          robot.performTurn = false;
          robot.state = MOVE_STATE_STOP;
          }
          */
      }
      else{
        //Serial.println("I'm turning right");
        //leftMotor.motorSpeed = 70;  //0-->250
        leftMotor.state = MOTOR_STATE_FORWARD_INIT;
        robot.isReady = false;
        robot.performTurn = true;
        robot.leftwhileturns = 0;
      }
      break;
    }

    
    case MOVE_STATE_FORWARD :
    {
      if(robot.isReady == true){
        
        //leftMotor.motorSpeed = 120;
        //rightMotor.motorSpeed = 120;
        leftMotor.state = MOTOR_STATE_FORWARD_INIT;
        rightMotor.state = MOTOR_STATE_FORWARD_INIT;
        robot.isReady = false;
        //robot.state = MOVE_STATE_WAIT;
      }
      
      else{
        //if(robot.leftwhileturns + robot.rightwhileturns> 100){
         if(robot.leftwhileturns>25){
          leftMotor.state = MOTOR_STATE_RELEASE;
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
        }
       if(robot.rightwhileturns>25){
          rightMotor.state = MOTOR_STATE_RELEASE;
          robot.leftwhileturns = 0;
          robot.rightwhileturns = 0;
        }
      }
      break;
    }
    
    case MOVE_STATE_WAIT:
    { 
      break;
    }
  }
}
