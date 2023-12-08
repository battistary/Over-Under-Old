#include "main.h"

void setPuncher() {
    // Puncher rotation sensor positions:
    // 300 -> Resting postion
    // 265-70° -> Slip gear
    while ( true ) {
        if ( controller.get_digital(E_CONTROLLER_DIGITAL_A) ) {
            while ( controller.get_digital(E_CONTROLLER_DIGITAL_A) ) {
                puncher = 127;
            }
            while ( rotationSensor.get_angle() < 30000 ) {
                puncher = 127;
            }
            while ( rotationSensor.get_angle() > 30000 ) {
                puncher = 127;
            }
            puncher = 0;
        }
    }
}
