#include "main.h"

// Controllers
extern okapi::Controller controller;

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

// Inertial Sensor
extern pros::Imu imu;

// Chassis Controller
extern std::shared_ptr<okapi::ChassisController> chassis;
