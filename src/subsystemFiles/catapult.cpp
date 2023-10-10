#include "main.h"

void setCata() {
    if (controller.get_digital(E_CONTROLLER_DIGITAL_A)) {
        catapult = (127.0 * 0.75);
    }
    else if (controller.get_digital(E_CONTROLLER_DIGITAL_B)) {
        catapult = (-127.0 * 0.75);
    }
    else {
        catapult = 0;
    }
}
