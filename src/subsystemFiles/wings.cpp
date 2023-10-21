#include "main.h"
#include "pros/misc.h"

bool wingLeft = false;
bool wingRight = false;

// Wing control functions
void setWings() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        if ( wingLeft == false ) {
            wingPistonLeft.set_value(1);
            wingLeft = true;
            pros::delay(500);
        }
        else if (wingLeft == true) {
            wingPistonLeft.set_value(0);
            wingLeft = false;
            pros::delay(500);
        }
    }
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        if ( wingRight == false ) {
            wingPistonRight.set_value(1);
            wingRight = true;
            pros::delay(500);
        }
        else if (wingRight == true) {
            wingPistonRight.set_value(0);
            wingRight = false;
            pros::delay(500);
        }
    }
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
            wingPistonRight.set_value(1);
            wingPistonLeft.set_value(1);
            wingRight = true;
            wingLeft = true;
            pros::delay(500);
        }
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            wingPistonRight.set_value(0);
            wingPistonLeft.set_value(0);
            wingRight = false;
            wingLeft = false;
            pros::delay(500);
        }
}
