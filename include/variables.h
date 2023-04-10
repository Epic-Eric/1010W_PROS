#ifndef VARIABLES_H
#define VARIABLES_H
#pragma once

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
inline constexpr int GYRO1 = 21;
inline constexpr int GYRO2= 2;

#endif