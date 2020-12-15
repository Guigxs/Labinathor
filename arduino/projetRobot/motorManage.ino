
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
      leftMotor.actualMotorSpeed = 65;
      rightMotor.actualMotorSpeed = 60;

      break;
    }
    
    case MOTOR_STATE_WAIT :
    {
      break;
    }

    
    case MOTOR_STATE_FORWARD_INIT :
    {
        startMillisL = millis();
        LM->run(FORWARD);
        
        //leftMotor.actualMotorSpeed = 65;
        LM->setSpeed(leftMotor.actualMotorSpeed);
        
        //leftMotor.state = MOTOR_STATE_FORWARD_ACCELERATE; //si on veut passer par une phase d'accélération
        leftMotor.state = MOTOR_STATE_FORWARD; //si on ne veut pas passer par la phase d'accélération
        break;
    }
    

    case MOTOR_STATE_FORWARD_ACCELERATE :
    {
      currentMillisL = millis();
      
      if(leftMotor.actualMotorSpeed < leftMotor.motorSpeed){
        if ((currentMillisL - startMillisL) > 350){       
          leftMotor.actualMotorSpeed += 2;
          LM->setSpeed(leftMotor.actualMotorSpeed);
          startMillisL = millis();
          }
      }
      
      else{
        leftMotor.state = MOTOR_STATE_FORWARD;
      }
      break;
    }

    case MOTOR_STATE_FORWARD:
    {
      LM->setSpeed(leftMotor.actualMotorSpeed);
      break;
    }
    
    case MOTOR_STATE_RELEASE : {
       LM->run(RELEASE);
       break;
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

    case MOTOR_STATE_FORWARD_INIT :
    {
      //Serial.println("Forward right init");
        RM->run(FORWARD);
        startMillisR = millis();
        
        //rightMotor.actualMotorSpeed = 60;
        RM->setSpeed(rightMotor.actualMotorSpeed);
        //rightMotor.state = MOTOR_STATE_FORWARD_ACCELERATE;//si on veut passer par une phase d'accélération
        rightMotor.state = MOTOR_STATE_FORWARD; 

    }
    
    case MOTOR_STATE_FORWARD_ACCELERATE :
    {
      currentMillisR = millis();

      if (rightMotor.actualMotorSpeed < rightMotor.motorSpeed){
        if ((currentMillisR - startMillisR) > 350){
            rightMotor.actualMotorSpeed += 2;
            RM->setSpeed(rightMotor.actualMotorSpeed);
            startMillisR = millis();      
        }
      }
      
      else{
        rightMotor.state = MOTOR_STATE_FORWARD;
      }
        
     break;
    }

    case MOTOR_STATE_FORWARD:
    {
      //Serial.println("In forward");
      RM->setSpeed(rightMotor.actualMotorSpeed);
      break;
    }

    case MOTOR_STATE_RELEASE : {
       RM->run(RELEASE);
       break;
    }
  }
}
