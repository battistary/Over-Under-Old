#include "main.h"

bool rachet = false;

void setLift() {
    if ( controller.get_digital(E_CONTROLLER_DIGITAL_L1) ) {
        lift = 127.0;
    }
    else if ( c::adi_digital_read(LIMIT_SWITCH) != HIGH && controller.get_digital(E_CONTROLLER_DIGITAL_L2) ) {
        lift = -127.0;
    }
    else {
        lift = 0;
    }

    if ( controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) ) {
        if ( rachet == false ) {
            liftRachet.set_value(1);
            rachet = true;
            pros::delay(250);
    }
        else {
            liftRachet.set_value(0);
            rachet = false;
            pros::delay(250);
        }
    }
}
