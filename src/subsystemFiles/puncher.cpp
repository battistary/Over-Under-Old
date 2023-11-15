#include "main.h"

void setPuncher() {
    // Catapult rotation sensor positions:
    // 335° -> Down
    // 200° -> Up
    // 265-70° -> Slip gear

    if ( controller.get_digital(E_CONTROLLER_DIGITAL_A) ) {
        while ( controller.get_digital(E_CONTROLLER_DIGITAL_A) ) {
            puncher = 127;
        }
        while ( rotationSensor.get_angle() < 34000 ) {
            puncher = 127;
        }
        puncher = 0;
    }
}
