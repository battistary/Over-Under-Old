#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    pros::Task endgameRumble {[=] {
        pros::delay(88000);
        controller.rumble(". .");
    }};
    pros::Task punch(setPuncher);
    pros::Task intake(setIntake);
    pros::Task lift(setLift);
    pros::Task wing(setWings);
    while ( true ) {
        double left = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) + controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
        double right = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) - controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
        driveLeft.move(left);
        driveRight.move(right);
        pros::delay(10);
    }
}
