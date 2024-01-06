#include "main.h"

// Variables
bool show_logo = true;
Gif gif("/usd/logo_stretched.gif", lv_scr_act());

// Controllers
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Motors
pros::Motor driveLeftFront(4, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftBack(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLilMiddleLeft(6, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);//good
pros::Motor driveRightFront(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightBack(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLilMiddleRight(5, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);

pros::Motor puncher(8, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor lift(9, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor intake(10, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);

// Motor Groups
pros::Motor_Group driveLeft({driveLeftFront, driveLeftBack, driveLilMiddleLeft});
pros::Motor_Group driveRight({driveRightFront, driveRightBack, driveLilMiddleRight});

// ADI Digital Outputs
// Limit Switch in 'A'
pros::ADIDigitalOut wingRight('B', false);
pros::ADIDigitalOut wingLeft('C', false);
pros::ADIDigitalOut liftRachet('H', false);

// Inertial Sensor
pros::Imu imu(7);

// Rotation Sensor
pros::Rotation rotationSensor(11);

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
    nullptr, // N/A - hortizontal tracking wheel 2
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
