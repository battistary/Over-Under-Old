#include "main.h"
#include "pros/motors.hpp"

// Variables
extern bool show_logo;
extern Gif gif;

// Controllers
extern pros::Controller controller;

// Motors
extern pros::Motor driveLeftFront;
extern pros::Motor driveLeftBack;
extern pros::Motor driveLilMiddleLeft;
extern pros::Motor driveRightFront;
extern pros::Motor driveRightBack;
extern pros::Motor driveLilMiddleRight;

extern pros::Motor catapult;
extern pros::Motor intake;
extern pros::Motor lift;

// Motor Groups
extern pros::Motor_Group driveLeft;
extern pros::Motor_Group driveRight;

// Pneumatic Pistons
extern pros::ADIDigitalOut liftPiston;
extern pros::ADIDigitalOut wingPistonLeft;
extern pros::ADIDigitalOut wingPistonRight;

// Inertial Sensor
extern pros::Imu imu;

// Rotation Sensor
extern pros::Rotation rotationSensor;

// LemLib chassis object
extern lemlib::Chassis chassis;
