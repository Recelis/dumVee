// MotorControl.cpp

#include "MotorControl.h"

// #define LEFT_MOTOR_1 11 //backward
// #define LEFT_MOTOR_2 10 //forward
// #define RIGHT_MOTOR_1 5 //backward 
// #define RIGHT_MOTOR_2 3 //forward
//#define GRIPPER_1 6 // open  
//#define GRIPPER_2 9 // close
// #define FRONT_LED 8
// #define RIGHT_LED 14
// #define BACK_LED 12
// #define LEFT_LED 13


void MotorControl::RightTurn(){
	digitalWrite(RIGHT_MOTOR_1, HIGH);
	digitalWrite(RIGHT_MOTOR_2, LOW);
  digitalWrite(LEFT_MOTOR_1, LOW);
  digitalWrite(LEFT_MOTOR_2, HIGH);
	
  digitalWrite(GRIPPER_1, LOW);
  digitalWrite(GRIPPER_2, LOW);

  digitalWrite(RIGHT_LED, HIGH);
	digitalWrite(FRONT_LED, LOW);
	digitalWrite(BACK_LED, LOW);
	digitalWrite(LEFT_LED, LOW);
  digitalWrite(HEADLIGHT, HIGH);
}

void MotorControl::LeftTurn(){
	digitalWrite(LEFT_MOTOR_1, HIGH);
	digitalWrite(LEFT_MOTOR_2, LOW);
  digitalWrite(RIGHT_MOTOR_1, LOW);
  digitalWrite(RIGHT_MOTOR_2, HIGH);
	digitalWrite(GRIPPER_1, LOW);
  digitalWrite(GRIPPER_2, LOW);

  digitalWrite(LEFT_LED, HIGH);
	digitalWrite(FRONT_LED, LOW);
	digitalWrite(BACK_LED, LOW);
	digitalWrite(RIGHT_LED, LOW);
  digitalWrite(HEADLIGHT, HIGH);
}

void MotorControl::Forward(){
	digitalWrite(RIGHT_MOTOR_1, LOW);
	digitalWrite(RIGHT_MOTOR_2, HIGH);
	digitalWrite(LEFT_MOTOR_1, LOW);
	digitalWrite(LEFT_MOTOR_2, HIGH);
	
	digitalWrite(GRIPPER_1, LOW);
  digitalWrite(GRIPPER_2, LOW);
	
	digitalWrite(FRONT_LED, HIGH);
	digitalWrite(LEFT_LED, LOW);
	digitalWrite(BACK_LED, LOW);
	digitalWrite(RIGHT_LED, LOW);
  digitalWrite(HEADLIGHT, HIGH);
}

void MotorControl::Reverse(){
	digitalWrite(RIGHT_MOTOR_1, HIGH);
	digitalWrite(RIGHT_MOTOR_2, LOW);
	digitalWrite(LEFT_MOTOR_1, HIGH);
	digitalWrite(LEFT_MOTOR_2, LOW);
	
	digitalWrite(GRIPPER_1, LOW);
  digitalWrite(GRIPPER_2, LOW);

  digitalWrite(BACK_LED, HIGH);
	digitalWrite(LEFT_LED, LOW);
	digitalWrite(FRONT_LED, LOW);
	digitalWrite(RIGHT_LED, LOW);
 digitalWrite(HEADLIGHT, HIGH);	
}

void MotorControl::GRIPPER_IN(){
	digitalWrite(RIGHT_MOTOR_1, LOW);
	digitalWrite(RIGHT_MOTOR_2, LOW);
	digitalWrite(LEFT_MOTOR_1, LOW);
	digitalWrite(LEFT_MOTOR_2, LOW);
	
	digitalWrite(GRIPPER_1, LOW);
  digitalWrite(GRIPPER_2, HIGH);
  
	digitalWrite(BACK_LED, LOW);
	digitalWrite(LEFT_LED, LOW);
	digitalWrite(FRONT_LED, LOW);
	digitalWrite(RIGHT_LED, LOW);
 digitalWrite(HEADLIGHT, LOW);	
}

void MotorControl::GRIPPER_OUT(){
	digitalWrite(RIGHT_MOTOR_1, LOW);
	digitalWrite(RIGHT_MOTOR_2, LOW);
	digitalWrite(LEFT_MOTOR_1, LOW);
  digitalWrite(LEFT_MOTOR_2, LOW);
	digitalWrite(GRIPPER_1, HIGH);
	digitalWrite(GRIPPER_2, LOW);
 
	digitalWrite(BACK_LED, LOW);
	digitalWrite(LEFT_LED, LOW);
	digitalWrite(FRONT_LED, LOW);
	digitalWrite(RIGHT_LED, LOW);	
  digitalWrite(HEADLIGHT, LOW);
}

void MotorControl::GRIPPER_BREAK(){
  digitalWrite(GRIPPER_1, HIGH);
  digitalWrite(GRIPPER_2, HIGH);
  Serial.println("GRIPPER_BREAK");
}

void MotorControl::STOP(){
  digitalWrite(RIGHT_MOTOR_1, LOW);
  digitalWrite(RIGHT_MOTOR_2, LOW);
  digitalWrite(LEFT_MOTOR_1, LOW);
  digitalWrite(LEFT_MOTOR_2, LOW);
  
  digitalWrite(BACK_LED, LOW);
  digitalWrite(LEFT_LED, LOW);
  digitalWrite(FRONT_LED, LOW);
  digitalWrite(RIGHT_LED, LOW); 
  digitalWrite(HEADLIGHT, LOW);
}

