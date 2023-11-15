#include "main.h"

void setLift() {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_L1)) {
        lift = 127.0;
    }
    else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2)) {
        lift = -127.0;
    }
    else {
        lift = 0;
    }
}
