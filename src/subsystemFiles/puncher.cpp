#include "main.h"

void setPuncher() {
    // Puncher rotation sensor positions:
    // 335° -> Down
    // 200° -> Up
    // 265-70° -> Slip gear

    if ( controller.get_digital(E_CONTROLLER_DIGITAL_A) ) {
        while ( controller.get_digital(E_CONTROLLER_DIGITAL_A) ) {
            puncher = 127;
            double left = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) + controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
            double right = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) - controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
            driveLeft.move(left);
            driveRight.move(right);
        }
        while ( rotationSensor.get_angle() < 34000 ) {
            puncher = 127;
            double left = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) + controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
            double right = controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) - controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
            driveLeft.move(left);
            driveRight.move(right);
        }
        puncher = 0;
    }
}
