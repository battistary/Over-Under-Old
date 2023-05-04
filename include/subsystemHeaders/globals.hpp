#include "main.h"

// Variables

// Controllers
extern okapi::Controller controller1;
extern okapi::Controller controller2;
extern pros::Controller master;

// Motors
extern pros::Motor driveLeftFront;
extern pros::Motor driveLeftCenter;
extern pros::Motor driveLeftBack;
extern pros::Motor driveRightFront;
extern pros::Motor driveRightCenter;
extern pros::Motor driveRightBack;
extern pros::Motor flywheel;
extern pros::Motor intake;

// Motor Groups
extern pros::Motor_Group driveLeft;
extern pros::Motor_Group driveRight;

// ADI Digital Outs

// Inertial Sensor
extern pros::Imu imu;

// Chassis Controller
extern std::shared_ptr<okapi::ChassisController> chassis;
