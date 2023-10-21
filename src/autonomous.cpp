#include "main.h"
#include "pros/llemu.hpp"

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
    if ( selector::auton == 1 || selector::auton == -1 ) { // Run pre-load auton
        // 1 motor turn = 10 inches
        // Turn at 38/128 voltage
        // Turns are relative, not absolute

        translate(-3.6, 50);
        rotate(-45, 38);
        translate(-3.6, 128);
        rotate(90, 38);
        translate(2.4, 50);
        intakePiston.set_value(1);
        translate(2.4, 50);
        intake = 127;
        pros::delay(1000);
        intake = 0;
        translate(-2.4, 50);
        rotate(180, 38);
        intake = -127;
        pros::delay(1000);
        intakePiston.set_value(0);
        rotate(180, 38);
        translate(-3.6, 128);
        translate(3.6, 50);
        rotate(-90, 38);
        translate(5.1, 50);
        rotate(-90, 38);
        translate(2.0, 50);
    }

    else if ( selector::auton == 2 || selector::auton == -2 ) {} // Run match-load auton

    else if ( selector::auton == 3 || selector::auton == -3 ) { // Run skills auton
        catapult = (-127.0 * 0.50);
    }

    while ( true ) {
        pros::delay(10);
    }
}
