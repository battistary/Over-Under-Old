#include "main.h"

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
