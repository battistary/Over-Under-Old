#include "main.h"

// Variables
extern bool show_logo;
extern Gif gif;

// Controllers
extern pros::Controller controller;

// Motors
extern pros::Motor driveLeftFront;
extern pros::Motor driveLeftBack;
extern pros::Motor driveRightFront;
extern pros::Motor driveRightBack;

extern pros::Motor cataL1;
extern pros::Motor cataL2;
extern pros::Motor cataR1;

extern pros::Motor intake;

// Motor Groups
extern pros::Motor_Group driveLeft;
extern pros::Motor_Group driveRight;
extern pros::Motor_Group catapult;

// Pneumatic Pistons
extern pros::ADIDigitalOut intakePiston1;
extern pros::ADIDigitalOut intakePiston2;

// Inertial Sensor
extern pros::Imu imu;

// Rotation Sensor
extern pros::Rotation rotation;

// LemLib chassis object
extern lemlib::Chassis chassis;
