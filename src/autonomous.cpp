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
        chassis.moveTo(52, -38, 2000);
        intake.move(-127);
        pros::delay(500);
        intake.move(0);

        // 2nd triball
        chassis.turnTo(18, -28, 2000);
        chassis.moveTo(18, -28, 2000);
        intake.move(127);
        chassis.turnTo(7, -24, 2000);
        chassis.moveTo(7, -24, 2000);
        pros::delay(500);
        intake.move(0);
        chassis.turnTo(32, -16, 2000);
        intake.move(-127);
        pros::delay(500);
        intake.move(0);

        // 3rd triball
        chassis.turnTo(24, 0, 2000);
        intake.move(127);
        chassis.moveTo(26, -7, 2000);
        pros::delay(500);
        intake.move(0);
        chassis.turnTo(46, -4, 2000);
        intake.move(-127);
        pros::delay(500);
        intake.move(0);

        // 4th triball
        chassis.turnTo(5, 1, 2000);
        intake.move(127);
        chassis.moveTo(9, 1, 2000);
        pros::delay(250);
        intake.move(0);
        chassis.turnTo(34, -4, 2000);
        chassis.moveTo(34, -4, 2000);
        intake.move(-127);
        pros::delay(500);
        intake.move(0);
    }

    else if ( selector::auton == 2 || selector::auton == -2 ) {                  // Opponent Side
        // 1st triball
        chassis.setPose(36, -58, -45);
        chassis.moveTo(-52, -39, 2000);
        intake.move(-127);
        pros::delay(500);
        intake.move(0);
        
        // 2nd triball
        chassis.turnTo(-30, -36, 2000);
        chassis.moveTo(-30, -36, 2000);
        chassis.turnTo(-25, -8, 2000);
        chassis.moveTo(-27, -17, 2000);
        intake.move(127);
        chassis.moveTo(-25, -7, 2000);
        pros::delay(500);
        intake.move(0);
        chassis.moveTo(-36, -58, 4000);
        chassis.turnTo(0, -58, 2000);
        intake.move(-127);
        pros::delay(500);
        intake.move(0);

        // Clear match load triball
        chassis.turnTo(-19, -69, 2000);
        chassis.moveTo(-51, -51, 2000);
        wingPistonRight.set_value(1);
        chassis.moveTo(-44, -63, 2000);
        wingPistonRight.set_value(0);
        chassis.turnTo(-1, -62, 2000);
        chassis.moveTo(-12, -60, 2000);

        // Elevation
        // Do l8r
    }

    else if ( selector::auton == 3 || selector::auton == -3 || selector::auton == 0 ) { // Skills auton
        while ( true ) {
            puncher = 0.75 * -127.0;
        }
    }
}