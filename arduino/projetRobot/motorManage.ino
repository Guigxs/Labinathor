
void APP_LEFT_MOTOR_INITIALIZE(){
  leftMotor.motorSpeed = 0;
  leftMotor.state = MOTOR_STATE_INIT;
  leftMotor.runConfig = RUN_RELEASE; 
  leftMotor.startConfigDone = false;
}
void APP_RIGHT_MOTOR_INITIALIZE(){
  rightMotor.motorSpeed = 0;
  rightMotor.state = MOTOR_STATE_INIT;
  rightMotor.runConfig = RUN_RELEASE;
  rightMotor.startConfigDone = false;
}



void APP_LEFT_MOTOR_TASKS(){
  switch(leftMotor.state){
    case MOTOR_STATE_INIT :
    {      
      leftMotor.state = MOTOR_STATE_WAIT;
      break;
    }
    
    case MOTOR_STATE_WAIT :
    {
      break;
    }
    

    case MOTOR_STATE_FORWARD :
    {
      currentMillisL = millis();
      if(leftMotor.startConfigDone == false){
        LM->run(FORWARD);
        startMillisL = millis();
        leftMotor.startConfigDone = true;
        leftMotor.actualMotorSpeed = 20;
        LM->setSpeed(leftMotor.actualMotorSpeed);
      }
      
      else if( (leftMotor.actualMotorSpeed < leftMotor.motorSpeed)  &&  ((currentMillisL - startMillisL) > 350)){       
        leftMotor.actualMotorSpeed += 2;
        LM->setSpeed(leftMotor.actualMotorSpeed);
        startMillisL = millis();
        }
      
      else{
        LM->setSpeed(leftMotor.actualMotorSpeed);
      }
     break;
    }
    
    case MOTOR_STATE_RELEASE : {
       LM->run(RELEASE);
    }
  }
}



void APP_RIGHT_MOTOR_TASKS(){
  switch(rightMotor.state){
    case MOTOR_STATE_INIT :
    {
      rightMotor.state = MOTOR_STATE_WAIT;
      break;
    }
    case MOTOR_STATE_WAIT :
    {
      break;
    }
    
    case MOTOR_STATE_FORWARD :
    {
      currentMillisR = millis();
      if(rightMotor.startConfigDone == false){
        RM->run(FORWARD);
        startMillisR = millis();
        rightMotor.startConfigDone = true;
        rightMotor.actualMotorSpeed = 30;
        RM->setSpeed(rightMotor.actualMotorSpeed);
      }
      
      else if( (rightMotor.actualMotorSpeed < rightMotor.motorSpeed)  &&  ((currentMillisR - startMillisR) > 350)){       
        rightMotor.actualMotorSpeed += 2;
        RM->setSpeed(rightMotor.actualMotorSpeed);
        startMillisR = millis();
      }
      else{
         RM->setSpeed(rightMotor.actualMotorSpeed);
      }
        
     break;
    }

    case MOTOR_STATE_RELEASE : {
       RM->run(RELEASE);
    }
  }
}
