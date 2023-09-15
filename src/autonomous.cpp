#include "main.h"
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
    if ( show_logo != true ) {
        Gif gif("/usd/logo_stretched.gif", lv_scr_act());
        show_logo = true;
    }

    if ( selector::auton == 1 || selector::auton == -1 ) {}      // Run auton #1 }

    else if ( selector::auton == 2 || selector::auton == -2 ) {} // Run auton #2 }
    
    else if ( selector::auton == 3 || selector::auton == -3 ) {} // Run auton #3 }
    
    show_logo = false;
//    gif.clean();

    while ( true ) {
        pros::delay(10);
    }
}
