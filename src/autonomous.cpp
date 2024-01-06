#include "main.h"

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
    if ( selector::auton == 1 || selector::auton == -1 ) {
        /*-----------------*/
        /*  Alliance Side  */
        /*-----------------*/

        // 1st triball
        chassis.setPose(38, -55, 45);       // Start
        chassis.moveTo(54, -41, 1000);
        chassis.turnTo(54, -24, 300);
        chassis.moveTo(54, -20, 1000);

        // 2nd triball
        lift.move_relative(2, 100);
        chassis.moveTo(54, -38, 1000);
        lift.move_relative(-2, 100);
        intake.move(127);
        turnMoveTo(9, -22, 300, 1400);
        chassis.turnTo(9, -7, 300);
        chassis.moveTo(9, -7, 1000);
        chassis.turnTo(47, -7, 600);
        intake.move(0);
        wingLeft.set_value(1);
        intake.move(-127);
        chassis.moveTo(47, -7, 1000);
        intake.move(0);
        wingLeft.set_value(0);

        // Contact colored bar
        chassis.moveTo(35, -10, 1000);
        chassis.turnTo(35, 53, 600);
        chassis.moveTo(35, -53, 2500);
        
        lift = 127;                         // Raise lift
        chassis.turnTo(60, -53, 600);       // Turn back towards colored bar
        chassis.moveTo(7, -53, 1000, 100);  // Contact colored bar
    }

    else if ( selector::auton == 2 || selector::auton == -2 ) {
        /*-----------------*/
        /*  Opponent Side  */
        /*-----------------*/

        chassis.setPose(-49, -58, 315);         // Start
        lift.move_relative(2, 100);             // Raise lift to drop intake
        chassis.moveTo(-54, -53, 1000);         // Move forward
        wingLeft.set_value(1);                  // Extend wing
        lift.move_relative(-2, 100);            // Lower lift
        chassis.moveTo(-49, -58, 500);          // Move back
        chassis.turnTo(-72, -48, 500);          // Turn
        wingLeft.set_value(0);                  // Retract wing to knock out triball
        pros::delay(500);                       // Delay to ensure wing retracts fully

        chassis.moveTo(-43, -59, 500);          // Staggered move away from barrier
        chassis.turnTo(-52, -58, 500);          // ^
        chassis.moveTo(-40, -58, 500);          // ^

        intake.move(127);                       // Spin intake
        chassis.turnTo(-31, -15, 1000);         // Turn towards middle triball
        chassis.moveTo(-31, -15, 3500, 100);    // Drive to middle triball
        pros::delay(500);                       // Delay to ensure intake
        intake.move(60);                        // Intake less to combat motor burn out

        chassis.moveTo(-40, -62, 3500, 100);    // Move back from middle
        chassis.turnTo(0, -62, 750);            // Turn
        intake.move(-127);                      // Shoot triball across
        pros::delay(500);                       // Delay
        intake.move(0);                         // Stop intake
        lift = 127;                             // Raise lift
        chassis.turnTo(-72, -62, 750);          // Turn 180 degrees
        chassis.moveTo(-7, -62, 1500);          // Contact colored bar
    }

    else if ( selector::auton == 3 || selector::auton == -3 || selector::auton == 0 ) {
        /*-----------------*/
        /*     Skills      */
        /*-----------------*/
        
        // Pre loads
        chassis.setPose(49, 58, 135);
        lift.move_relative(2, 100);
        chassis.moveTo(54, -41, 1000);
        chassis.turnTo(54, -24, 300);
        lift.move_relative(-2, 100);
        chassis.moveTo(54, -20, 1000);

        // Move to match load zone
        chassis.turnTo(59, 50, 500, true);
        chassis.moveTo(59, 50, 1000);
        chassis.turnTo(-44, 0, 1000);
        driveLeft = -30;
        driveRight = -30;

        // Set drivetrain brake mode to hold
        driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveLilMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveLilMiddleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        // Wham bam punch kick kapow wowie zowie
        puncher = 127;
        pros::delay(39000); //5 secs for testing
        puncher = 0;
        driveLeft = 0;
        driveRight = 0;

        // Set drivetrain brake mode to brake
        driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveLilMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveLilMiddleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

        // Drive across
        turnMoveTo(35, 58, 500, 1000);
        turnMoveTo(-41, 58, 500, 2000);

        // 1st ram
        turnMoveTo(-60, 26, 500, 1000);
        
        // 2nd ram
        chassis.moveTo(-60, 39, 1000);
        turnMoveTo(-33, 39, 500, 1000);
        turnMoveTo(-19, 18, 500, 1000);
        turnMoveTo(-19, 0, 500, 1000);
        wingLeft.set_value(1);
        wingRight.set_value(1);
        turnMoveTo(-44, 0, 500, 1000);
        pros::delay(200);

        // 3rd ram
        chassis.moveTo(-19, 0, 1000);
        driveLeft = 127;
        driveRight = 127;
        pros::delay(3000);
        driveLeft = 0;
        driveRight = 0;

        /*// Hang
        wingRight.set_value(0);
        wingLeft.set_value(0);
        turnMoveTo(-39, -59, 500, 1000);
        lift.move_relative(4, 100); //edit the turn. idk what fully up is
        pros::delay(1700);
        lift = 127; //This keeps it up?
        liftRachet.set_value(1);
        chassis.moveTo(1, -58, 1000);
        lift = 0
        lift.move_relative(-2, 100);8*/
    }
}
