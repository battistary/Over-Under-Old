#include "main.h"
#include "pros/misc.h"

void setIntake() {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_R1)) {
        intake = 127.0;
    }
    else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2)) {
        intake = -127.0;
    }
    else {
        intake = 0;
    }
}

void setPistons() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        intakePiston1.set_value(1);
        intakePiston2.set_value(1);
    }
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        intakePiston1.set_value(0);
        intakePiston2.set_value(0);
    }
}