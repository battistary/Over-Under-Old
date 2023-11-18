#include "main.h"

bool rachet = false;

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

        if ( controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) ) {
            if ( rachet == false ) {
                liftPiston.set_value(1);
                rachet = true;
                pros::delay(500);
        }
            else {
                liftPiston.set_value(0);
                rachet = false;
                pros::delay(500);
            }
        }
    }
    else {
        if ( controller.get_digital(E_CONTROLLER_DIGITAL_L1) ) {
            lift = 127.0;
        }
        else {
            lift = 0;
        }

        if ( controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) ) {
            if ( rachet == false ) {
                liftPiston.set_value(1);
                rachet = true;
                pros::delay(500);
        }
            else {
                liftPiston.set_value(0);
                rachet = false;
                pros::delay(500);
            }
        }
    }
}
