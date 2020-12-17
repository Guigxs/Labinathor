#include <Adafruit_MotorShield.h>
#define counterL A3
#define counterR A2


Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(1);
int counterLM = 0;
int counterRM = 0;
int vitL = 84;
int vitR = 71;
int data = 50;

void setup() {
  Serial.begin(9600);

  AFMS.begin();
  leftMotor->setSpeed(vitL);
  rightMotor->setSpeed(vitR);
  Serial.print("G0");
  
}

void loop() {

  if(Serial.available())
      {
        data = Serial.parseInt(SKIP_WHITESPACE);
        leftMotor->run(RELEASE);
        rightMotor->run(RELEASE);
      }

  if (data == 0){
    leftMotor->run(RELEASE);
    rightMotor->run(RELEASE);
  }
  
  if (data == 2){
    counterLM = analogRead(counterL);
    counterRM = analogRead(counterR);

    leftMotor->run(FORWARD);
    rightMotor->run(FORWARD);

    delay(500);
    data = 0;
    Serial.print("o");
  }

    if (data == 1){
      
      leftMotor->run(FORWARD);
      delay(900);
      data = 0;
    
    }

    if (data == 3){
      
      rightMotor->run(FORWARD);
      delay(825);
      data = 0;
    
    }

    if (data == 4){
    
    leftMotor->run(FORWARD);
    rightMotor->run(BACKWARD);
    delay(925);
    data = 0;
    
    }
  }
