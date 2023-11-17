#include "lemlib/pose.hpp"
#include "main.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"

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
        // drive.cpp backup notes
        // 1 motor turn = 10 inches
        // Turn at 38/127 voltage
        // Turns are relative, not absolute
    if ( selector::auton == 1 || selector::auton == -1 ) {                       // Alliance Side
        // 1st triball
        chassis.setPose(38, -55, 45);
        chassis.moveTo(54, -41, 1000);
        chassis.turnTo(54, -24, 1000);
        chassis.moveTo(54, -22, 1000);

        // 2nd triball
        chassis.moveTo(54, -38, 1000);
        chassis.turnTo(7, -25, 1000);
        chassis.moveTo(21, -29, 1000);
        intake.move(127);
        chassis.moveTo(10, -25, 1000);
        pros::delay(1000);
        intake.move(0);
        chassis.turnTo(10, -12, 1000);
        chassis.moveTo(10, -12, 1000);
        chassis.turnTo(47, -12, 1000);
        intake.move(-20);
        chassis.moveTo(47, -12, 1000);
        intake.move(0);

        // 3rd triball
        chassis.moveTo(23, -12, 1000);
        chassis.turnTo(24, -5, 1000);
        intake.move(127);
        chassis.moveTo(24, -5, 1000);
        pros::delay(1000);
        intake.move(0);
        chassis.moveTo(24, -12, 1000);
        chassis.turnTo(47, -12, 1000);
        chassis.moveTo(47, -12, 1000);

        // Contact colored bar
        chassis.moveTo(33, -12, 1000);
        chassis.turnTo(33, -56, 1000);
        chassis.moveTo(33, -56, 1000);
        chassis.turnTo(60, -56, 1000);
        chassis.moveTo(17, -56, 1000);
        lift.move_relative(620, 100);
        intake.move(127);
        chassis.moveTo(10, -56, 1000, 75);
    }

    else if ( selector::auton == 2 || selector::auton == -2 ) {                  // Opponent Side
        // 1st triball
        chassis.setPose(-36, -58, -45);
        chassis.moveTo(-52, -39, 1000);
        intake.move(-127);
        pros::delay(500);
        intake.move(0);
        
        // 2nd triball
        chassis.turnTo(-30, -36, 1000);
        chassis.moveTo(-30, -36, 1000);
        chassis.turnTo(-25, -8, 1000);
        chassis.moveTo(-27, -17, 1000);
        intake.move(127);
        chassis.moveTo(-25, -7, 1000);
        pros::delay(500);
        intake.move(0);
        chassis.moveTo(-36, -58, 4000);
        chassis.turnTo(0, -58, 1000);
        intake.move(-127);
        pros::delay(500);
        intake.move(0);

        // Clear match load triball
        chassis.turnTo(-19, -69, 1000);
        chassis.moveTo(-51, -51, 1000);
        wingPistonRight.set_value(1);
        chassis.moveTo(-44, -63, 1000);
        wingPistonRight.set_value(0);
        chassis.turnTo(-1, -62, 1000);
        chassis.moveTo(-12, -60, 1000);

        // Elevation
        // Do l8r
    }

    else if ( selector::auton == 3 || selector::auton == -3 || selector::auton == 0 ) { // Skills auton
        while ( true ) {
            puncher = 0.75 * -127.0;
        }
    }
}