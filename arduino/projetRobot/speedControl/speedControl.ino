
void docountLM()  
{
  counterLM++;  
} 
void docountRM()  
{
  counterRM++;  
}


void timerInterrupt()
{
  Timer1.detachInterrupt();  //stop the timer


  Serial.print("Left motor speed: "); 
  Serial.println(counterLM,DEC);  
  
  Serial.print("Right motor speed: "); 
  Serial.println(counterRM,DEC); 
  if(counterLM > counterRM){
    leftMotor.motorSpeed -= 2;
    rightMotor.motorSpeed += 2;
  }
  else if(counterRM < counterLM){
    leftMotor.motorSpeed += 2;
    rightMotor.motorSpeed -= 2;
  }
  
  Timer1.attachInterrupt(timerInterrupt);  //enable the timer
  counterLM = 0;  
  counterRM = 0;
  leftMotor.state = MOTOR_STATE_CONFIGURE;
  rightMotor.state = MOTOR_STATE_CONFIGURE;
}


void SPEED_CONTROL_INITILIAZE(){
  Timer1.initialize(100000); // set timer for 1sec
  attachInterrupt(0, docountLM, RISING);  // increase counter when speed sensor pin goes High
  attachInterrupt(1, docountRM, RISING);  // increase counter when speed sensor pin goes High
  Timer1.attachInterrupt(timerInterrupt); // enable the timer
}
