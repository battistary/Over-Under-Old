#include "main.h"

void setCata() {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_A)) {
        catapult = 0.75 * 127.0;
    }
    else if (controller.get_digital(E_CONTROLLER_DIGITAL_B)) {
        catapult = 0.75 * -127.0;
    }
    else {
        catapult = 0;
    }
}
