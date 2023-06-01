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
        .withMotors({1, 2, 3}, {4, 5, 6})
        // Speed gearset, 36:84 gear ratio, 4.0" wheel diameter, Currently Unknown wheel track
        .withDimensions({AbstractMotor::gearset::blue, (36.0 / 84.0)}, {{4_in, 0_in}, imev5BlueTPR})
        .withGains(
            {0.001, 0, 0.0001}, // Distance controller gains
            {0.001, 0, 0.0001}, // Turn controller gains
            {0.001, 0, 0.0001}) // Angle controller gains
        .withMaxVelocity(600)
        .build();
