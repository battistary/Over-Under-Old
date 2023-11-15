#include "main.h"

void setCata() {
    // Catapult rotation sensor positions:
    // 335° -> Down
    // 265° -> Up
    // 265-70° -> Slip gear

    if ( controller.get_digital(E_CONTROLLER_DIGITAL_A) ) {
        while ( controller.get_digital(E_CONTROLLER_DIGITAL_A) ) {
            catapult = 127;
        }
        while ( rotationSensor.get_angle() < 33500 ) {
            catapult = 127;
        }
        catapult = 0;
    }
}
