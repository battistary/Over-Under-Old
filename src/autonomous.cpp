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
        chassis.moveTo(54, -20, 1000);

        // 2nd triball
        chassis.moveTo(54, -38, 1000);
        chassis.turnTo(5, -24, 1000);
        chassis.moveTo(21, -29, 1000);
        intake.move(127);
        chassis.moveTo(10, -25, 1000);
        pros::delay(1500);
        intake.move(0);
        chassis.turnTo(10, -12, 1000);
        chassis.moveTo(10, -12, 1000);
        chassis.turnTo(47, -12, 1000);
        wingPistonLeft.set_value(1);
        intake.move(-127);
        chassis.moveTo(47, -12, 1000);
        intake.move(0);
        wingPistonLeft.set_value(0);

        // 3rd triball
        //chassis.moveTo(35, -12, 1000);
        //chassis.turnTo(24, 0, 1000);
        //intake.move(127);
        //chassis.moveTo(29, -4, 1000);
        //pros::delay(1000);
        //intake.move(0);
        //chassis.moveTo(35, -12, 1000);
        //chassis.turnTo(47, -12, 1000);
        //intake.move(-127);
        //chassis.moveTo(47, -12, 1000);
        //intake.move(0);

        // Contact colored bar
        chassis.moveTo(33, -12, 1000);
        chassis.turnTo(33, -56, 1000);
        chassis.moveTo(33, -56, 2000);
        lift.move_relative(4, 100);
        chassis.turnTo(60, -56, 1000);
        //chassis.moveTo(17, -56, 1000);
        chassis.moveTo(10, -56, 1000, 75);
    }

    else if ( selector::auton == 2 || selector::auton == -2 ) {                  // Opponent Side
        // 1st triball
        chassis.setPose(-36, -58, 90);
        intake.move(-127);

        // 2nd triball
        chassis.turnTo(-22, -69, 1500);
        chassis.moveTo(-55, -45, 1500);
        chassis.turnTo(-43, -63, 1500);
        wingPistonRight.set_value(1);
        chassis.moveTo(-43, -63, 1500);
        wingPistonRight.set_value(0);

        // 3rd triball
        chassis.turnTo(-25, -7, 1500);
        chassis.moveTo(-24, -13, 1500);
        intake.move(127);
        chassis.moveTo(-24, -6, 1500);
        pros::delay(1000);
        intake.move(0);
        chassis.moveTo(-39, -56, 1500);
        chassis.turnTo(-9, -56, 1500);
        intake.move(-127);
        pros::delay(1000);
        intake.move(0);

        // Contact colored bar
        chassis.turnTo(-52, -56, 1500);
        lift.move_relative(4, 100);
        chassis.moveTo(-9, -56, 1500);
    }

    else if ( selector::auton == 3 || selector::auton == -3 || selector::auton == 0 ) { // Skills auton
        // Match loads
        chassis.setPose(-42, -58, 135);
        chassis.moveTo(-57, -46, 1500);
        chassis.turnTo(46, -7, 1500);
        wingPistonRight.set_value(1);
        puncher.move(127);
        pros::delay(45000);
        puncher.move(0);

        // Push bot / plowing
        chassis.turnTo(-31, -58, 1500);
        chassis.moveTo(-31, -58, 1500);
        chassis.moveTo(37, -58, 2000);
        wingPistonLeft.set_value(1);
        wingPistonRight.set_value(1);
        chassis.turnTo(59, -28, 1500);
        chassis.moveTo(59, -28, 1500);
        chassis.moveTo(54, -40, 1500);
        chassis.moveTo(59, -28, 1500);
        
        // Elevation
        chassis.turnTo(36, -57, 1500);
        chassis.moveTo(36, -57, 1500);
        chassis.turnTo(6, -57, 1500);
        chassis.moveTo(6, -57, 1500);
        lift.move_relative(4, 100);
        chassis.moveTo(-2, -57, 1000);
        liftPiston.set_value(1);
        lift.move_relative(-2, 100);
    }
}
