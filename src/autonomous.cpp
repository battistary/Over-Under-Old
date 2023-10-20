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

        lcd::initialize();
        translate(2.4, 50);
        rotate(90, 38);
        translate(2.4, 50);
        rotate(90, 38);
        translate(-3.7, 128);
        rotate(90, 38);
        translate(4.8, 50);




        pros::lcd::print(2, "%f", imu.get_rotation());
    }

    else if ( selector::auton == 2 || selector::auton == -2 ) {} // Run match-load auton

    else if ( selector::auton == 3 || selector::auton == -3 ) {} // Run skills auton

    while ( true ) {
        pros::delay(10);
    }
}
