#include "main.h"

// Controllers
okapi::Controller controller(ControllerId::master);

// Motors
// Each raw encoder count is 0.375 degrees, so there are 960 in one revolution
pros::Motor driveLeftFront(1, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftCenter(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftBack(3, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightFront(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightCenter(5, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightBack(6, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(7, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

// Motor Groups
pros::Motor_Group driveLeft({driveLeftBack, driveLeftCenter, driveLeftFront});
pros::Motor_Group driveRight({driveRightBack, driveRightCenter, driveRightFront});

// Inertial Sensor
pros::Imu imu(8);

// Chassis Controller PID
std::shared_ptr<okapi::ChassisController> chassis =
    ChassisControllerBuilder()
        .withMotors({2, 3, 4}, {13, 18, 19})
        // Speed gearset, 36:48 gear ratio, 3.25" wheel diameter, 10.75" wheel track0
        //.withDimensions({AbstractMotor::gearset::blue, (48.0 / 36.0)}, {{3.25_in, 25_in}, imev5BlueTPR})
        .withDimensions({AbstractMotor::gearset::blue, (48.0 / 36.0)}, {{3.25_in, 10.75_in}, imev5BlueTPR})
        .withGains(
            {0.0015, 0.0, 0.000048},//{0.0015,  0, 0.00008 }, //{0.00063, 0, 0.000014},	// Distance controller gains
            {0.0019,  0, 0.000024}, // Turn controller gains
            {0.0015, 0.0, 0.000048})//{0.001,   0, 0.0001  })	// Angle controller gains
        .withMaxVelocity(600)
        .build();
