

//PARCOURS TEST : 
int myMoves[] = {1, 2, 2, 1, 3, 3};
//int myMoves[] = {2, 2, 2, 2, 2, 2};


void setup() {
  AFMS.begin();
  SPEED_CONTROL_INITILIAZE ();
  APP_COMMUNICATION_INITIALIZE();  
  
  APP_LEFT_MOTOR_INITIALIZE();
  APP_RIGHT_MOTOR_INITIALIZE();
  APP_MOTOR_DIRECTION_INIT();

  startMillis = millis(); //start the millis function.
}

int i = 0;
void loop() {
  APP_LEFT_MOTOR_TASKS();
  APP_RIGHT_MOTOR_TASKS();
  APP_MOTOR_DIRECTION_TASKS();
  APP_COMMUNICATION_TASKS();

  
     if(robot.isReady){
       if(myMoves[i] == 1){
          robot.state = MOVE_STATE_FORWARD;

       }
       else if(myMoves[i] == 2){
          robot.state = MOVE_STATE_TURN_LEFT;

       }
       else if(myMoves[i] == 3){
          robot.state = MOVE_STATE_TURN_RIGHT;
       }
      
       i++;
       if(i == 6){
         i = 0;
      }
     }
     
}
