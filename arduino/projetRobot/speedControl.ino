
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

  if(counterLM > counterRM){
    if(counterLM > counterRM + 1){
      leftMotor.motorSpeed -= 2;
      rightMotor.motorSpeed += 2;
    }
    else{
      leftMotor.motorSpeed -= 1;
      rightMotor.motorSpeed += 1;
    }
  }
  
  else if(counterRM > counterLM){
    if(counterRM > counterLM + 1){
      leftMotor.motorSpeed += 2;
      rightMotor.motorSpeed -= 2;
    }
    else{
      leftMotor.motorSpeed += 1;
      rightMotor.motorSpeed -= 1;
    }
  }
  
  Timer1.attachInterrupt(timerInterrupt);  //enable the timer
  counterLM = 0;  
  counterRM = 0;
  leftMotor.state = MOTOR_STATE_CONFIGURE;
  rightMotor.state = MOTOR_STATE_CONFIGURE;
}


void SPEED_CONTROL_INITILIAZE(){
  //Mise à 5V des deux capteurs

  Timer1.initialize(100000); // set timer for 1sec
  attachInterrupt(0, docountLM, RISING);  // increase counter when speed sensor pin goes High
  attachInterrupt(1, docountRM, RISING);  // increase counter when speed sensor pin goes High
  Timer1.attachInterrupt(timerInterrupt); // enable the timer
}
