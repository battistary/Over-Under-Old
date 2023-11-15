#include "main.h"
#include "pros/adi.h"

void setLift() {
    if ( c::adi_digital_read(LIMIT_SWITCH) != HIGH ) {
        if ( controller.get_digital(E_CONTROLLER_DIGITAL_L1) ) {
            lift = 127.0;
        }
        else if ( controller.get_digital(E_CONTROLLER_DIGITAL_L2) ) {
            lift = -127.0;
        }
        else {
            lift = 0;
        }
    }
    else {
        if ( controller.get_digital(E_CONTROLLER_DIGITAL_L1) ) {
            lift = 127.0;
        }
        else {
            lift = 0;
        }
    }
}
