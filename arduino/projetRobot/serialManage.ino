void APP_COMMUNICATION_INITIALIZE(){
  Serial.begin(9600);
  serial.state = SERIAL_STATE_INIT;
}

void APP_COMMUNICATION_TASKS(){
  switch (serial.state){
    case SERIAL_STATE_INIT:
    {
      serial.state = SERIAL_STATE_WAIT;
      break;
    }
    
    case SERIAL_STATE_TURN_LEFT:
    {
      Serial.println("3");
      robot.state = MOVE_STATE_TURN_LEFT;
      Serial.println("0");
      serial.state = SERIAL_STATE_WAIT;
      
      break;
    }
    case SERIAL_STATE_TURN_RIGHT:
    {
      Serial.println("1");
      robot.state = MOVE_STATE_TURN_RIGHT;
      Serial.println("0");
      serial.state = SERIAL_STATE_WAIT;
      break;
    }
    case SERIAL_STATE_FORWARD:
    {
      //Serial.println("Allons tout droit");
      robot.state = MOVE_STATE_FORWARD;
      serial.state = SERIAL_STATE_WAIT;
      break;
    }
    case SERIAL_STATE_BACKWARD:
    {
      //Serial.println("Faisons marche arrière");
      robot.state = MOVE_STATE_BACKWARD;
      serial.state = SERIAL_STATE_WAIT;
      break;
    }
    case SERIAL_STATE_STOP:
    {
      //Serial.println("Arrêtons nousssssssssss");
      robot.state = MOVE_STATE_STOP;
      serial.state = SERIAL_STATE_WAIT;
      break;
    }
    case SERIAL_STATE_WAIT:
    {
      if(Serial.available())
      {
        int a = Serial.parseInt(SKIP_WHITESPACE);
        //Serial.print("Recieved : ");
        //Serial.println(a);

        if (a>=-1 && a<=5){
          serial.state = a;
        }
        /*else{
          serial.state = SERIAL_STATE_WAIT;
          //Serial.println("Integer does not exist!");
        }*/

      }
      break;
    }
  }
}
