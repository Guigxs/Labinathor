void APP_COMMUNICATION_INITIALIZE(){
  Serial.begin(9600);
}

void APP_COMMUNICATION_TASKS(){
  switch (serial.state){
    case SERIAL_STATE_INIT:
    {
      robot.state = MOVE_STATE_INIT;
      serial.state = 0;
      break;
    }
    case SERIAL_STATE_TURN_LEFT:
    {
      robot.state = MOVE_STATE_TURN_LEFT;
      serial.state = 0;
      break;
    }
    case SERIAL_STATE_TURN_RIGHT:
    {
      robot.state = MOVE_STATE_TURN_RIGHT;
      serial.state = 0;
      break;
    }
    case SERIAL_STATE_FORWARD:
    {
      robot.state = MOVE_STATE_FORWARD;
      serial.state = 0;
      break;
    }
    case SERIAL_STATE_BACKWARD:
    {
      robot.state = MOVE_STATE_BACKWARD;
      serial.state = 0;
      break;
    }
    case SERIAL_STATE_STOP:
    {
      // TODO: Stop the robot
      serial.state = 0;
      break;
    }
    case SERIAL_STATE_WAIT:
    {
      if(Serial.available())
      {
        int a = Serial.parseInt();
        Serial.print("Recieved : ");
        Serial.println(a);

        if (a>=-1 && a<=5){
          serial.state = a;
        }
        else{
          serial.state = 5;
        }
      }
      robot.state = MOVE_STATE_WAIT;
      break;
    }
  }
}
