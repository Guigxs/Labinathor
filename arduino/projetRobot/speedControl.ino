
void docountLM()  
{
  counterLM++;
  robot.leftwhileturns++;
} 
void docountRM()  
{
  counterRM++; 
  robot.rightwhileturns++;
}


void timerInterrupt()
{
  Timer1.detachInterrupt();  //stop the timer


  /*Serial.print("Left motor counter: "); 
  Serial.println(counterLM,DEC);  
  
  Serial.print("Right motor counter: "); 
  Serial.println(counterRM,DEC);*/ 

  if(robot.performTurn ==false){
    
  Serial.print("------- interrupt: (r,l)");
  Serial.print(counterRM);
  Serial.print(counterLM);
  Serial.println("-------");
      if(counterLM > counterRM){
        if(counterLM > counterRM + 1){
          leftMotor.actualMotorSpeed -= 3;
          rightMotor.actualMotorSpeed += 3;
        }
        else{
          leftMotor.actualMotorSpeed -= 1;
          rightMotor.actualMotorSpeed += 1;
        }
      }
      
      else if(counterRM > counterLM){
        if(counterRM > counterLM + 1){
          leftMotor.actualMotorSpeed += 3;
          rightMotor.actualMotorSpeed -= 3;
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
  //leftMotor.state = MOTOR_STATE_CONFIGURE;
  //rightMotor.state = MOTOR_STATE_CONFIGURE;
}


void SPEED_CONTROL_INITILIAZE(){
  //Mise à 5V des deux capteurs

  Timer1.initialize(50000); // set timer for 0.1 sec
  attachInterrupt(0, docountLM, RISING);  // increase counter when speed sensor pin goes High
  attachInterrupt(1, docountRM, RISING);  // increase counter when speed sensor pin goes High
  Timer1.attachInterrupt(timerInterrupt); // enable the timer
}
