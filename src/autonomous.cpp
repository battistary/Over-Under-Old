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
        // drive.cpp backup notes
        // 1 motor turn = 10 inches
        // Turn at 38/127 voltage
        // Turns are relative, not absolute
    if ( selector::auton == 1 ) {                       // Red Alliance Side
        chassis.setPose(41, -57, imu.get_rotation());
        chassis.follow("red_alliance_side.txt", 2000, 10);
    }

    else if ( selector::auton == 2 ) {                  // Red Opponent Side
        chassis.setPose(-41, -57, imu.get_rotation());
        chassis.follow("red_opponent_side.txt", 2000, 10);
    }

    else if ( selector::auton == -1 ) {                 // Blue Alliance Side
        chassis.setPose(-41, 57, imu.get_rotation());
        chassis.follow("blue_alliance_side.txt", 2000, 10);
    }

    else if ( selector::auton == -2 ) {                 // Blue Opponent Side
        chassis.setPose(41, 57, imu.get_rotation());
        chassis.follow("blue_opponent_side.txt", 2000, 10);
    }

    else if ( selector::auton == 3 || selector::auton == -3 || selector::auton == 0 ) { // Skills auton
        chassis.setPose(0, 0, imu.get_rotation());

        while ( true ) {
            catapult = 0.5 * -127.0;
        }
    }
}