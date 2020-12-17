
void docountLM()  
{
  counterLM++;
  robot.leftwhileturns++;
  
  if (robot.state == MOVE_STATE_TURN_RIGHT){
    if (robot.leftwhileturns == 22){
      robot.leftwhileturns = 0;
      robot.state = MOVE_STATE_STOP;
      robot.performTurn = false;
    }
   }
} 
void docountRM()  
{
  counterRM++; 
  robot.rightwhileturns++;
  
  if (robot.state == MOVE_STATE_TURN_LEFT){
    if (robot.rightwhileturns == 19){
      robot.rightwhileturns = 0;
      robot.state = MOVE_STATE_STOP;
      robot.performTurn = false;
    }
   }
}


void timerInterrupt()
{
  Timer1.detachInterrupt();  //stop the timer
  if(robot.performTurn ==false){
      
      if(counterLM > counterRM){
        if(counterLM > counterRM + 1){
          leftMotor.actualMotorSpeed -= 2;
          rightMotor.actualMotorSpeed += 2;
        }
        else{
          leftMotor.actualMotorSpeed -= 1;
          rightMotor.actualMotorSpeed += 1;

        }
      }
      
      else if(counterRM > counterLM){
        if(counterRM > counterLM + 1){
          leftMotor.actualMotorSpeed += 2;
          rightMotor.actualMotorSpeed -= 2;
        }
        else{
          leftMotor.actualMotorSpeed += 1;
          rightMotor.actualMotorSpeed -= 1;
        }
      }

  }
  Timer1.attachInterrupt(timerInterrupt);  //enable the timer
  counterLM = 0;  
  counterRM = 0;
}


void SPEED_CONTROL_INITILIAZE(){
  //Mise à 5V des deux capteurs

  Timer1.initialize(60000); // set timer for 0.1 sec
  Timer1.attachInterrupt(timerInterrupt); // enable the timer

  attachInterrupt(1, docountLM, RISING);  // increase counter when speed sensor pin goes High
  attachInterrupt(0, docountRM, RISING);  // increase counter when speed sensor pin goes High
}
