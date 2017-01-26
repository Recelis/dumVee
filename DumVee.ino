#include "NewPing.h"
#include "MotorControl.h"

#define FRONT_LED 8
#define RIGHT_LED 14
#define BACK_LED 12
#define LEFT_LED 13
#define HEADLIGHT 7
#define LEFT_MOTOR_1 11 //backward
#define LEFT_MOTOR_2 10 //forward
#define RIGHT_MOTOR_1 5 //backward 
#define RIGHT_MOTOR_2 3 //forward
#define GRIPPER_1 6 // open  
#define GRIPPER_2 9 // close

#define MOTORSWITCH 15
int distance = 0;
MotorControl Control;
int gripper = 0; // 0 goes inwards, 1 goes outwards.
bool gripperFlag = false;
bool obstacleDetected = false;
int escape = 0; // escape protocols 0, 1, 2,3
int motorRead = 0;
#define TRIGPIN 2
#define ECHOPIN 4


int ping()
{
    // pause for 50ms between scans
    delay(5);

    // send ping
    digitalWrite(TRIGPIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN, LOW);

    // read echo
    long duration = pulseIn(ECHOPIN, HIGH);

    // convert distance to cm
    unsigned int centimetres = int(duration / 2 / 29.1);

    return centimetres;
}

void setup(){
  Serial.begin(9600);
  // set pins
  pinMode(FRONT_LED,OUTPUT);
  pinMode(RIGHT_LED,OUTPUT);
  pinMode(BACK_LED,OUTPUT);
  pinMode(LEFT_LED,OUTPUT);
  pinMode(HEADLIGHT, OUTPUT);
  
  pinMode(LEFT_MOTOR_1, OUTPUT);
  pinMode(LEFT_MOTOR_2, OUTPUT);
  pinMode(RIGHT_MOTOR_1, OUTPUT);
  pinMode(RIGHT_MOTOR_2, OUTPUT);
  pinMode(GRIPPER_1, OUTPUT);
  pinMode(GRIPPER_2, OUTPUT);

  pinMode(MOTORSWITCH, INPUT);
  // set the trig pin to output (send sound waves)
  pinMode(TRIGPIN, OUTPUT);

  // set the echo pin to input (receive sound waves)
  pinMode(ECHOPIN, INPUT);
}

void loop(){
  distance = ping();
  Serial.println(distance);
  if (gripperFlag == true){
    Serial.println("GRIPPER_HIGH");
  } else{
    Serial.println("GRIPPER_LOW");
  }
  motorRead = digitalRead(MOTORSWITCH);
  if (motorRead == HIGH) Serial.println("HIGH");
  if (motorRead == LOW) Serial.println("LOW");
    
  if (distance <= 6){
    if (distance <= 2){
      Control.STOP();
      if (gripperFlag)
      {
        Control.GRIPPER_OUT();
        gripperFlag = false;
        delay(3000);
      } else Control.GRIPPER_BREAK();
        
    }
    else{
      Control.STOP();
      if (!gripperFlag){
        Control.GRIPPER_IN();
        gripperFlag = true;
        delay(3000);    
      } else Control.GRIPPER_BREAK();
    }
  }
  else{
    if (gripperFlag){
      Control.STOP();
        Control.GRIPPER_OUT();
        gripperFlag = false;  
        delay(3000);
    } else Control.GRIPPER_BREAK();
    if (motorRead == HIGH){
      if (distance > 15 && !obstacleDetected){
      Control.Forward();
      }
      if (distance <= 15){
        obstacleDetected = true;
        if (escape == 0) escape = 1;
      }
      if (obstacleDetected){
        if (distance > 15){
          obstacleDetected = false;
          escape = 0;
        }
        switch(escape){
        case(1):
          Serial.println("LEFT");
          Control.LeftTurn();
          delay(1000);
          escape = 2;
          break;
        case(2):
          Serial.println("RIGHT");
          Control.RightTurn();
          delay(2000);
          escape = 3;
          break;
        case(3):
          Serial.println("REVERSE");
          Control.Reverse();
          delay(1000);
          Control.LeftTurn();
          delay(3000);
          escape = 1;
          break;
        }
      }  
    }
    else {
      Control.STOP();
      if (distance > 100) digitalWrite(HEADLIGHT, HIGH);
    }
  } 
}
