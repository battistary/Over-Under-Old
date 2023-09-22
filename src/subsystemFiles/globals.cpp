#include "main.h"
#include "pros/motors.h"

// Variables
bool show_logo = true;
Gif gif("/usd/logo_stretched.gif", lv_scr_act());

// Controllers
pros::Controller controller(E_CONTROLLER_MASTER);

// Motors
pros::Motor driveLeftFront(20, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);   // port 20, reversed
pros::Motor driveLeftBack(7, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);     // port 6, reversed
pros::Motor driveRightFront(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS); // port 11, not reversed
pros::Motor driveRightBack(6, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);   // port 1, not reversed

pros::Motor cataL1(1, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cataL2(2, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cataR1(3, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);

pros::Motor intake(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);

// Motor Groups
pros::Motor_Group driveLeft({driveLeftBack, driveLeftFront});
pros::Motor_Group driveRight({driveRightBack, driveRightFront});
pros::Motor_Group catapult({cataL1, cataL2, cataR1});

// Pneumatic Pistons
pros::ADIDigitalOut intakePiston1('A', false);
pros::ADIDigitalOut intakePiston2('B', false);

// Inertial Sensor
pros::Imu imu(8);

// Rotation Sensor
pros::Rotation rotation_sensor(5);

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
