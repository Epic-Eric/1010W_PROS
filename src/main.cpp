#include "main.h"
#include "lemlib/api.hpp"
#include "variables.h"
#define calc_distance(rot) (double) rot / 360 * 2.75 * M_PI

//Lemlib drivetrain
lemlib::Drivetrain_t drivetrain {
    &left, // left drivetrain motors
    &right, // right drivetrain motors
    TRACKWIDTH, // track width
    WHEELDIA, // wheel diameter
    RPM // wheel rpm
};

//lemlib TWs
lemlib::TrackingWheel forw_tracking_wheel(&TW_forw, TRACKDIA, FORW_DIS);
lemlib::TrackingWheel side_tracking_wheel(&TW_side, TRACKDIA, SIDE_DIS);

//lemlib odom
lemlib::OdomSensors_t sensors {
    &forw_tracking_wheel, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2 (don't have)
    &side_tracking_wheel, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &gyro1 // inertial sensor
};

// forward/backward PID
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    40 // slew rate
};
 
 
// create the chassis
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

void screen(){
	while (true) {
        lemlib::Pose pose = chassis.getPose(); // get the current position of the robot
        pros::lcd::print(0, "x: %f", pose.x); // print the x position
        pros::lcd::print(1, "y: %f", pose.y); // print the y position
        pros::lcd::print(2, "heading: %f", pose.theta); // print the heading
		pros::lcd::print(3, "front: %f inches", calc_distance(TW_forw.get_value()));
		pros::lcd::print(4, "side: %f inches", calc_distance(TW_side.get_value()));
		pros::lcd::print(5, "heading: %f degrees", gyro1.get_heading());
		pros::lcd::print(6, "Intake: %f rpm", Intake.get_actual_velocity());
        pros::delay(10);
    }
}

void initialize() {
	pros::lcd::initialize();
	//pros::lcd::set_text(1, "Hello PROS User!");
	// gyro1.reset(true); //blocking other tasks until it's done
	// gyro2.reset(true);
	chassis.calibrate();
	pros::Task screenTask(screen,TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"Get robot position");
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
void autonomous() {
	int rollerDegrees = 200;
	chassis.setPose(-58, 40, 90);//red roller
	pros::delay(50);
	chassis.moveTo(-59, 40, 1000);//move to red roller
	pros::delay(50);
	Intake.move_relative(rollerDegrees, 100);//spin roller
	pros::delay(50);
	chassis.moveTo(-42, 40, 1000);//move back
	pros::delay(50);
	chassis.turnTo(-42, 64, 1000);//turn to 2nd roller
	pros::delay(50);
	chassis.moveTo(-42, 64, 1000);//go to 2nd roller
	pros::delay(50);
	Intake.move_relative(rollerDegrees, 100);//spin roller
	pros::delay(50);
	chassis.moveTo(-42, 54, 1000);//back off
	pros::delay(50);
	chassis.turnTo(0, 0, 1000);//turn to middle
	pros::delay(50);
	Left_string.set_value(1); //shoot
	pros::delay(50);
	Right_string.set_value(1); //shoot
}

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
	//Break modes
	left.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
	right.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
	Cata.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	Intake.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

	while(true){
		//Chassis
		double turn = (double)master.get_analog(ANALOG_RIGHT_X)/(double)127*100; //controller joystick -127 -> 127
		double forw = (double)master.get_analog(ANALOG_LEFT_Y)/(double)127*100;
		double turnVolt = turnSensitivity*(turn*120); //PROS voltage go from -12000 -> 12000 volts
		double forwVolt = forw * 120 * (1 - (std::abs(turnVolt)/12000 * turnImportance)); 
		left.move_voltage(forwVolt + turnVolt);//left
		right.move_voltage(forwVolt - turnVolt);//right

		//Intake and Roller
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
			Intake.move_voltage(12000);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
			Intake.move_voltage(-12000);
		}
		else Intake.brake();

		//Cata
		if(Limit.get_value()==0){ //0 for not pressed, 1 for pressed
			Cata.move_voltage(12000);
		}
		else Cata.brake();
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
			while(Limit.get_value()==1) Cata.move_voltage(12000);
		}

		//Endgame
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
			Left_string.set_value(1); // 1 for fire, 0 for not
		}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
			Right_string.set_value(1);
		}
		pros::delay(2);
	}


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
