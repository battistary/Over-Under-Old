#include "lemlib/pose.hpp"
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
    if ( selector::auton == 1 || selector::auton == -1 ) {                       // Alliance Side
        chassis.setPose(38, -55, 45);
        chassis.moveTo(63, -26, 2000);  // Tested working

        /* Experimental */

        lemlib::Pose pose = chassis.getPose();
        chassis.turnTo(pose.x, -32, 2000);
        chassis.moveTo(pose.x, -32, 2000);
//
        //chassis.turnTo(55, -53, 2000);
        //chassis.moveTo(55, -53, 2000);
        //wingPistonLeft.set_value(1);
//
        //chassis.turnTo(0, -53, 2000);
        //wingPistonLeft.set_value(0);
//
        //chassis.turnTo(36, -53, 2000);
        //chassis.moveTo(36, -53, 2000);
//
        //chassis.turnTo(0, -60, 2000);
        //chassis.moveTo(0, -60, 2000);
//
        //wingPistonRight.set_value(1);
    }

    else if ( selector::auton == 2 || selector::auton == -2 ) {                  // Opponent Side
        chassis.setPose(-38, -55, -45);
        chassis.moveTo(-63, -26, 2000); // Tested working

        /* Experimental */

        lemlib::Pose pose = chassis.getPose();
        chassis.turnTo(-1 * pose.x, -32, 2500);
        chassis.moveTo(-1 * pose.x, -32, 2000);
//
        //chassis.turnTo(-55, -53, 2000);
        //chassis.moveTo(-55, -53, 2000);
        //wingPistonLeft.set_value(1);
//
        //chassis.turnTo(0, -53, 2000);
        //wingPistonLeft.set_value(0);
//
        //chassis.turnTo(-36, -53, 2000);
        //chassis.moveTo(-36, -53, 2000);
//
        //chassis.turnTo(0, -60, 2000);
        //chassis.moveTo(0, -60, 2000);
//
        //wingPistonRight.set_value(1);
    }

    else if ( selector::auton == 3 || selector::auton == -3 || selector::auton == 0 ) { // Skills auton
        while ( true ) {
            catapult = 0.75 * -127.0;
        }
    }
}