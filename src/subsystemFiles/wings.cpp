#include "main.h"

bool pushBotMode = false;

void setWings() {
    if ( controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP) ) {
        if ( pushBotMode == false ) {
            wings.set_value(1);
            pushBotMode = true;
            pros::delay(500);
        }
        else {
            wings.set_value(0);
            pushBotMode = false;
            pros::delay(500);
        }
    }
}
