#include "autoSelect/selection.h"
#include "main.h"
#include "pros/motors.h"

void turnMoveTo(float x, float y, int turnTimeout, int moveTimeout) {
    chassis.turnTo(x, y, turnTimeout);
    chassis.moveTo(x, y, moveTimeout);
}

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
        lift.move_relative(2, 100);
        pros::delay(500);
        lift.move_relative(-2, 100);
        chassis.moveTo(54, -41, 1000);
        chassis.turnTo(54, -24, 500);
        chassis.moveTo(54, -20, 1000);

        // 2nd triball
        chassis.moveTo(54, -38, 1000);
        intake.move(127);
        turnMoveTo(7, -27, 500, 1400);
        pros::delay(300);
        intake.move(0);
        chassis.turnTo(7, -12, 500);
        chassis.moveTo(7, -12, 1000);
        chassis.turnTo(47, -12, 600);
        wingLeft.set_value(1);
        intake.move(-127);
        chassis.moveTo(47, -12, 1000);
        intake.move(0);
        wingLeft.set_value(0);

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
        chassis.turnTo(0, -56, 1000);
        /*
        lift.move_relative(4.2, 100);
        chassis.turnTo(60, -56, 600);
        //chassis.moveTo(17, -56, 1000);
        chassis.moveTo(7, -56, 1000, 100);
        */
    }

    else if ( selector::auton == 2 || selector::auton == -2 ) {                  // Opponent Side
        // 1st triball
        chassis.setPose(-36, -58, 90);
        lift.move_relative(2, 100);
        pros::delay(500);
        lift.move_relative(-2, 100);
        intake.move(-127);
        pros::delay(500);
        intake.move(0);

        // 2nd triball
        chassis.turnTo(-22, -69, 1500);
        chassis.moveTo(-55, -45, 1500);
        chassis.turnTo(-43, -63, 1500);
        wingRight.set_value(1);
        chassis.moveTo(-52, -54, 500);
        chassis.turnTo(-23, -59, 500);
        wingRight.set_value(0);
        pros::delay(250);
        wingRight.set_value(1);
        pros::delay(250);
        wingRight.set_value(0);
        chassis.moveTo(-35, -59, 750);
        chassis.moveTo(-23, -59, 750);

        // 3rd triball
        /* chassis.turnTo(-25, -7, 1500);
        chassis.moveTo(-24, -13, 1500);
        intake.move(127);
        chassis.moveTo(-24, -6, 1500);
        pros::delay(1000);
        intake.move(0);
        chassis.moveTo(-39, -56, 1500);
        chassis.turnTo(-9, -56, 1500);
        intake.move(-127);
        pros::delay(1000);
        intake.move(0); */

        // Contact colored bar
        chassis.turnTo(-52, -59, 1500);
        lift.move_relative(4.2, 100);
        pros::delay(2000);
        lift = 30;
        chassis.moveTo(-5, -59, 1500);
    }

    else if ( selector::auton == 3 || selector::auton == 0 ) {  // New Pure Pursuit Skills Auton
        // Pre loads
        chassis.setPose(36, 60, 315);
        lift.move_relative(2, 100);
        pros::delay(500);
        lift.move_relative(-2, 100);

        // Path 1
        chassis.moveTo(60, 27, 1000, true);

        // Path 2
        turnMoveTo(59, 48, 500, 1000);
        chassis.turnTo(-44, 16, 1000);

        // Set drivetrain brake mode to hold
        driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveLilMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveLilMiddleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        // Wham bam punch kick kapow wowie zowie
        puncher = 127;
        pros::delay(30000);
        puncher = 0;

        // Set drivetrain brake mode to brake
        driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveLilMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveLilMiddleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

        // Path 3
        turnMoveTo(35, 60, 500, 1000);
        turnMoveTo(-30, 57, 500, 2000);
        wingLeft.set_value(1);
        wingRight.set_value(1);
        intake.move(127);

        // 1st pushbot ram
        wingRight.set_value(0);
        turnMoveTo(-59, 39, 500, 1000);
        intake.move(-127);
        chassis.moveTo(-59, 27, 1000);
        intake.move(127);
        pros::delay(500);
        intake.move(0);
        chassis.moveTo(-59, 39, 1000, true);
        intake.move(-127);
        turnMoveTo(-30, 39, 500, 1000);
        chassis.moveTo(-30, 8, 1000);
        turnMoveTo(-44, 8, 500, 1000);

        // 2nd pushbot ram
        chassis.moveTo(-30, 8, 500);
        chassis.turnTo(-9, 21, 250);
        turnMoveTo(-18, 0, 500, 1000);
        chassis.turnTo(-13, -8, 250);
        turnMoveTo(-30, -10, 500, 1000);
        chassis.moveTo(-44, 10, 1000);

        // 3rd pushbot ram
        wingLeft.set_value(0);
        wingRight.set_value(0);
        chassis.moveTo(-33, -10, 1000);
        


        
        pros::delay(500);
        intake.move(127);
        chassis.follow("5fw.txt", 5000, 10);
        intake.move(-127);
        pros::delay(500);
        intake.move(127);
        chassis.follow("6fw.txt", 5000, 10);
        intake.move(-127);
        pros::delay(500);
        intake.move(0);

        // Contact elevation bar
        wingLeft.set_value(0);
        wingRight.set_value(0);
        chassis.follow("7fw.txt", 5000, 10);
        lift.move_relative(4, 1000);
        chassis.moveTo(0, 62, 1000);
        liftRachet.set_value(1);
        lift.move_relative(-3, 100);
    }

    else if ( selector::auton == -3 ) { // Puncher Skills
        // Match loads
        chassis.setPose(-42, -58, 135);
        lift.move_relative(2, 100);
        pros::delay(500);
        lift.move_relative(-2, 100);
        chassis.moveTo(-57, -46, 1500);
        chassis.turnTo(46, -7, 1500);
        wingRight.set_value(1);
        wingLeft.set_value(1);
        puncher.move(127);
        pros::delay(45000);
        puncher.move(0);
        wingRight.set_value(0);
        wingLeft.set_value(0);

        // Push bot / plowing
        chassis.turnTo(-31, -58, 1500);
        chassis.moveTo(-31, -58, 1500);
        chassis.moveTo(37, -58, 2000);
        wingRight.set_value(1);
        wingLeft.set_value(1);
        chassis.turnTo(59, -28, 1500);
        chassis.moveTo(59, -28, 1500);
        chassis.moveTo(54, -40, 1500);
        chassis.moveTo(59, -28, 1500);
        
        // Elevation
        chassis.turnTo(36, -57, 1500);
        chassis.moveTo(36, -57, 1500);
        chassis.turnTo(6, -57, 1500);
        chassis.moveTo(6, -57, 1500);
        lift.move_relative(4.2, 100);
        chassis.moveTo(-2, -57, 1000);
        liftRachet.set_value(1);
        lift.move_relative(-2, 100);
    }
}
