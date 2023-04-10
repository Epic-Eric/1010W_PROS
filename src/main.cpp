#include "main.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motors.h"
#include "variables.h"

void initialize() {
	//Motors
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor LeftUp(LEFTUP, MOTOR_GEAR_BLUE, true);
	pros::Motor LeftMiddle(LEFTMIDDLE, MOTOR_GEAR_BLUE);
	pros::Motor LeftDown(LEFTDOWN, MOTOR_GEAR_BLUE, true);
	pros::Motor RightUp(RIGHTUP, MOTOR_GEAR_BLUE);
	pros::Motor RightMiddle(RIGHTMIDDLE, MOTOR_GEAR_BLUE, true);
	pros::Motor RightDown(RIGHTDOWN, MOTOR_GEAR_BLUE);
	pros::Motor Intake(INTAKE, MOTOR_GEAR_BLUE);
	pros::Motor Cata(CATA, MOTOR_GEAR_RED);

	//Sensors
	pros::ADIEncoder TW_forw (FORW_TOP, FORW_BOTTOM);
	pros::ADIEncoder TW_side (SIDE_TOP, SIDE_BOTTOM);
	pros::ADIDigitalOut Left_string (LEFT_STRING);
	pros::ADIDigitalOut Right_string (RIGHT_STRING);
	pros::ADIDigitalIn Limit (LIMIT);
	pros::Imu gyro1 (GYRO1);
	pros::Imu gyro2 (GYRO2);
	gyro1.reset(true); //blocking other tasks until it's done
	gyro2.reset(true);


	//pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() 
{

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	

	// while (true) {
	// 	pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
	// 	                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
	// 	                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
	// 	int left = master.get_analog(ANALOG_LEFT_Y);
	// 	int right = master.get_analog(ANALOG_RIGHT_Y);

	// 	left_mtr = left;
	// 	right_mtr = right;

	// 	pros::delay(20);
	// }
}
