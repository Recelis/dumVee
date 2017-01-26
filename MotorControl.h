// MotorControl.h
#include "arduino.h"
#ifndef MotorControl_h
#define MotorControl_h

#define LEFT_MOTOR_1 11 //backward
#define LEFT_MOTOR_2 10 //forward
#define RIGHT_MOTOR_1 5 //backward 
#define RIGHT_MOTOR_2 3 //forward
#define GRIPPER_1 6 // open  
#define GRIPPER_2 9 // close

#define HEADLIGHT 7
#define FRONT_LED 8
#define RIGHT_LED 14
#define BACK_LED 12
#define LEFT_LED 13

class MotorControl{
	public:
		void RightTurn();
		void LeftTurn();
		void Forward();
		void Reverse();
    void GRIPPER_IN();
    void GRIPPER_OUT();
    void GRIPPER_BREAK();
    void STOP(); 
	private:

};

#endif
