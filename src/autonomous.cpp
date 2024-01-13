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
    // Set drivetrain brake mode to brake
    driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    driveLilMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    driveLilMiddleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

    if ( selector::auton == 1 || selector::auton == -1 ) {
        /*-----------------*/
        /*  Alliance Side  */
        /*-----------------*/

        chassis.setPose(38, -55, 45);           // Start
        chassis.moveTo(54, -41, 1000);          // Move diagonally to align with goal
        chassis.turnTo(54, -24, 300);           // Turn towards goal
        chassis.moveTo(54, -20, 1000);          // Ram 1st triball into goal
    
        // 2nd triball  
        lift.move_relative(2, 100);             // Raise lift to drop intake
        chassis.moveTo(54, -38, 1000);          // Reverse away from goal
        lift.move_relative(-2, 100);            // Lower lift
        intake.move(127);                       // Spin intake
        turnMoveTo(9, -22, 300, 1400);          // Go to and intake closest middle triball
        chassis.turnTo(9, -7, 300);             // Turn to be somewhat parallel with middle barrier
        chassis.moveTo(9, -7, 1000);            // Move to triball
        chassis.turnTo(47, -7, 600);            // Turn to face goal
        intake.move(0);                         // Stop intake
        wingLeft.set_value(1);                  // Extend left wing
        intake.move(-127);                      // Shoot out triball
        chassis.moveTo(47, -7, 1000);           // Ram 2 triballs into goal
        intake.move(0);                         // Stop intake
        wingLeft.set_value(0);                  // Retract left wing
    
        // Contact colored bar  
        chassis.moveTo(35, -10, 1000);          // Reverse away from goal
        chassis.turnTo(35, 53, 600);            // Turn away from colored bar
        chassis.moveTo(35, -53, 2500);          // Reverse towards the colored bar
        
        lift = 127;                             // Raise lift
        chassis.turnTo(60, -53, 600);           // Turn back towards colored bar
        chassis.moveTo(7, -53, 1000, 100);      // Contact colored bar
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

        // Eliminations Code
        //chassis.moveTo(-13, -62, 1000);       // Almost contact colored bar but don't risk it
        //chassis.moveTo(-40, -62, 1000);       // Back up
    }

    else if ( selector::auton == 3 || selector::auton == -3 || selector::auton == 0 ) {
        /*-----------------*/
        /*     Skills      */
        /*-----------------*/
        
        // Pre loads
        chassis.setPose(49, 58, 135);           // Start
        chassis.moveTo(60, 47, 500);            // Move diagonally to align with goal
        chassis.turnTo(60, 31, 300);            // Turn towards goal
        chassis.moveTo(60, 20, 1000);           // Ram 1st two triballs into goal
        lift.move_relative(4.2, 100);           // Raise lift

        chassis.moveTo(60, 44, 750);            // Move in front of match-loading position
        chassis.turnTo(-44, 17, 500);           // Turn to face opposite goal
        chassis.moveTo(66, 43, 1000);           // Back into match-loading position
        lift = 45;                              // Hold lift up
        

        // Set drivetrain brake mode to hold
        driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveLilMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        driveLilMiddleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        puncher = 127;                          // Wham bam punch kick pow boom wowie zowie
        pros::delay(30000);                     // 30s delay
        puncher = 0;                            // Stop puncher
        driveLeft = 0;                          // Stop left drive
        driveRight = 0;                         // Stop right drive
        chassis.setPose(54, 55, 225);           // Set position after finishing shooting
        while ( pros::c::adi_digital_read(LIMIT_SWITCH) != HIGH ) { // Drops lift
            lift = -127;
        }
        lift = 0;
        while ( controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) ) {
            puncher = 127;
        }
        while ( rotationSensor.get_angle() < 30000 ) {
            puncher = 127;
        }
        while ( rotationSensor.get_angle() > 30000 ) {
            puncher = 127;
        }
        puncher = 0;

        // Set drivetrain brake mode to brake
        driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveLilMiddleRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
        driveLilMiddleLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

        turnMoveTo(57, 37, 300, 400);           // Move away from bar
        chassis.turnTo(67, 37, 300);            // Turn to 45 degree for backwards crossing field
        chassis.moveTo(40, 54, 1000);           // Align for crossing
        turnMoveTo(24, 60, 500, 750);           // Center with passage
        // 1st ram
        turnMoveTo(-26, 60, 500, 1000);         // Cross
        chassis.moveTo(-59, 41, 500);           // Plow triballs towards goal
        chassis.turnTo(-59, 20, 300);           // Turn to goal
        chassis.moveTo(-59, -20, 750);          // Ram into goal *** MAX SPEED (timeouted) (+20 originally)
        chassis.moveTo(-59, 38, 500);           // Back away from goal
        chassis.moveTo(-59, -20, 750);          // Ram into goal *** MAX SPEED (timeouted) (+20 originally)
        //chassis.setPose(-65, 30);             // FIND HEADING
        chassis.moveTo(-59, 38, 500);           // Back away from goal
        chassis.turnTo(-39, 38, 300);           // Turn away from goal
        
        // 2nd ram
        chassis.moveTo(-36, 33, 1000);          // Move towards mid bar
        chassis.turnTo(-17, 26, 500);           // Turn for triball sweep
        wingLeft.set_value(1);                  // Deploy left wing
        wingRight.set_value(1);                 // Deploy right wing
        chassis.moveTo(-17, 26, 1000);          // Move towards middle of field
        turnMoveTo(-17, 13, 500, 1000);         // Turn & move for ram
        wingRight.set_value(0);
        wingLeft.set_value(1);                  // Extend left wing
        turnMoveTo(-72, 13, 500, 1000);         // Turn & Ram into goal
        chassis.setPose(-45, 13, 270);          // Check degrees

        // 3rd ram
        chassis.moveTo(-23, 13, 750);           // Back away from goal
        chassis.turnTo(-18, 6, 500, true);      // Turn for sweep
        wingLeft.set_value(1);                  // Extend left wing
        wingRight.set_value(1);                 // Extend right wing
        turnMoveTo(-17, -10, 500, 1000);        // Move to 0 y-alignment
        turnMoveTo(-72, -10, 500, 1000);        // Turn & ram into goal *** MAX SPEED (timeouted) (-44 orignally)
        chassis.setPose(-45, -10, 270);         // Check degrees

        // 4th ram
        chassis.moveTo(-33, 10, 750);           // Drive backwards out from goal
        wingRight.set_value(0);                 // Retract right wing
        turnMoveTo(-25, -22, 400, 750);         // Sweep triballs for ram
        turnMoveTo(-49, -41, 300, 750);         // Move closer to goal
        turnMoveTo(-60, -41, 300, 750);         // Line up to goal
        turnMoveTo(-60, -19, 500, 1000);        // Turn & ram into goal
        chassis.moveTo(-60, -40, 1000);         // Back away from goal
        
        ////////////////////////
        /*
        Old Final Ram
        driveLeft = 127;                        // Set left drivetrain motors to max voltage
        driveRight = 127;                       // Set right drivetrain motors to max voltage
        pros::delay(3000);                      // Delay for 3 seconds
        driveLeft = 0;                          // Set left drivetrain motor voltage to 0
        driveRight = 0;                         // Set right drivetrain motor voltage to 0
        chassis.moveTo(-24, 0, 1000);           // Stop contacting goal so that we're legal
        
        //driveLeft = -30;                        // Back up against match load bar
        //driveRight = -30;                       // Back up against match load bar

        //chassis.moveTo(60, 36, 500);            // Back up away from goal
        //chassis.turnTo(70, 26, 300);            // Turn away from goal
        //chassis.moveTo(50, 46, 400);            // Zig away from goal
        //chassis.turnTo(30, 26, 300);            // Turn towards match load bar
        //chassis.moveTo(54, 50, 300);            // Zag towards match load bar

        lift.move_relative(-2, 100);

        // Move to match load zone
        chassis.turnTo(59, 50, 500, true);
        chassis.moveTo(59, 50, 1000);
        chassis.turnTo(-44, 0, 1000);
        driveLeft = -30;
        driveRight = -30;

        // Wham bam punch kick kapow wowie zowie
        puncher = 127;
        pros::delay(39000); //5 secs for testing
        puncher = 0;
        driveLeft = 0;
        driveRight = 0;

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

        // Hang
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
