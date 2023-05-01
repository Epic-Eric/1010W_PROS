#include "main.h"

//Motors
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor LeftUp(LEFTUP, pros::E_MOTOR_GEAR_BLUE);
pros::Motor LeftMiddle(LEFTMIDDLE, MOTOR_GEAR_BLUE, true);
pros::Motor LeftDown(LEFTDOWN, MOTOR_GEAR_BLUE, true);
pros::Motor RightUp(RIGHTUP, MOTOR_GEAR_BLUE, true);
pros::Motor RightMiddle(RIGHTMIDDLE, MOTOR_GEAR_BLUE);
pros::Motor RightDown(RIGHTDOWN, MOTOR_GEAR_BLUE);
pros::Motor Intake(INTAKE, MOTOR_GEAR_BLUE);
pros::Motor Cata(CATA, MOTOR_GEAR_RED);
pros::MotorGroup left ({LeftUp,LeftMiddle,LeftDown});
pros::MotorGroup right ({RightUp,RightMiddle,RightDown});

//Sensors
pros::ADIEncoder TW_forw (FORW_TOP, FORW_BOTTOM);
pros::ADIEncoder TW_side (SIDE_TOP, SIDE_BOTTOM);
pros::ADIDigitalOut Left_string (LEFT_STRING);
pros::ADIDigitalOut Right_string (RIGHT_STRING);
pros::ADIDigitalIn Limit (LIMIT);
pros::Imu gyro1 (GYRO1);
pros::Imu gyro2 (GYRO2);