#include "main.h"
#include "pros/motors.h"
#include "pros/motors.hpp"

// Variables
bool show_logo = true;
Gif gif("/usd/logo_stretched.gif", lv_scr_act());

// Controllers
pros::Controller controller(E_CONTROLLER_MASTER);

// Motors
pros::Motor driveLeftFront(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftBack(12, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLilMiddleLeft(13, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightFront(20, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightBack(19, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLilMiddleRight(18, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);

pros::Motor catapult(14, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(15, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor lift(16, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

// Motor Groups
pros::Motor_Group driveLeft({driveLeftFront, driveLeftBack, driveLilMiddleLeft});
pros::Motor_Group driveRight({driveRightFront, driveLeftBack, driveLilMiddleRight});

// Pneumatic Pistons
pros::ADIDigitalOut liftPiston('A', false);
pros::ADIDigitalOut wingPistonLeft('G', false);
pros::ADIDigitalOut wingPistonRight('H', false);

// Inertial Sensor
pros::Imu imu(17);

// Rotation Sensor
//pros::Rotation rotation_sensor(20);

// Drivetrain struct
lemlib::Drivetrain_t drivetrain {
    &driveLeft,     // left drivetrain motors
    &driveRight,    // right drivetrain motors
    11,             // 11" track width
    4,              // 4" wheel diameter
    400             // wheel rpm
};

// Odometry struct
lemlib::OdomSensors_t sensors {
    nullptr, // N/A - vertical tracking wheel 1
    nullptr, // N/A - vertical tracking wheel 2
    nullptr, // N/A - horizontal tracking wheel 1
    nullptr, // N/A - hortizontal tracking wheel 2 - wouldn't help much anyway
    &imu     // inertial sensor
};

// Forward/backward PID
lemlib::ChassisController_t lateralController {
    8,      // kP
    30,     // kD
    1,      // smallErrorRange
    100,    // smallErrorTimeout
    3,      // largeErrorRange
    500,    // largeErrorTimeout
    5       // slew rate
};
 
// Turning PID
lemlib::ChassisController_t angularController {
    4,      // kP
    40,     // kD
    1,      // smallErrorRange
    100,    // smallErrorTimeout
    3,      // largeErrorRange
    500,    // largeErrorTimeout
    0       // slew rate
};

// Create chassis object
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
