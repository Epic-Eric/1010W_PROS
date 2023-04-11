#ifndef VARIABLES_H
#define VARIABLES_H
#pragma once
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/misc.hpp"


//Drive Ports
inline constexpr int LEFTUP = 11;
inline constexpr int LEFTMIDDLE = 3;
inline constexpr int LEFTDOWN = 4;
inline constexpr int RIGHTUP = 17;
inline constexpr int RIGHTMIDDLE = 13;
inline constexpr int RIGHTDOWN = 16;
//Subsystem Ports
inline constexpr int INTAKE = 19;
inline constexpr int CATA = 1;
//Sensor Ports
inline constexpr char FORW_TOP = 'G';
inline constexpr char FORW_BOTTOM = 'H';
inline constexpr char SIDE_TOP = 'E';
inline constexpr char SIDE_BOTTOM = 'F';
inline constexpr char LEFT_STRING = 'A';
inline constexpr char RIGHT_STRING = 'C';
inline constexpr char LIMIT = 'B';
inline constexpr int GYRO1 = 10;
inline constexpr int GYRO2= 2;

extern pros::Controller master;
extern pros::Motor LeftUp;
extern pros::Motor LeftMiddle;
extern pros::Motor LeftDown;
extern pros::Motor RightUp;
extern pros::Motor RightMiddle;
extern pros::Motor RightDown;
extern pros::Motor Intake;
extern pros::Motor Cata;
extern pros::MotorGroup left;
extern pros::MotorGroup right;

//Sensors
extern pros::ADIEncoder TW_forw;
extern pros::ADIEncoder TW_side;
extern pros::ADIDigitalOut Left_string;
extern pros::ADIDigitalOut Right_string;
extern pros::ADIDigitalIn Limit;
extern pros::Imu gyro1;
extern pros::Imu gyro2;
extern pros::Motor myMotor;

//opcontrol variables
inline constexpr double turnImportance = 0.3; //How much turning slows down the speed of forward, 0 doesn't affect, 1 stops going forward
inline constexpr double turnSensitivity = 0.8; //How sensitive a turn is, 0 doesn't turn, 1 most sensitive

//Chassis + Odom variables
inline constexpr int RPM = 480; //drivetrain RPM
inline constexpr float WHEELDIA = 3.25; //drivetrain wheel diameter
inline constexpr float TRACKWIDTH = 11; //distance between the center of left and right wheel
inline constexpr float WHEELBASE = 9; //the distance of center of front and back wheel, not used

inline constexpr float TRACKDIA = 2.75; //tracking wheel diameter
inline constexpr float FORW_DIS = 2.1875; //distance perpendicular from forw tracking wheel to the center
inline constexpr float SIDE_DIS = 1.875; //distance perpendicular from side tracking wheel to the center

#endif