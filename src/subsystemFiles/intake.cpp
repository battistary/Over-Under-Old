#include "main.h"

bool raise_intake = false;

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

void setPiston() {
  if (controller.get_digital(E_CONTROLLER_DIGITAL_A)) { // Set to controller2 for comp
    if ( raise_intake == false ) {
      intakePiston.set_value(1);
      raise_intake = true;
      pros::delay(500);
    }
    else {
      intakePiston.set_value(0);
      raise_intake = false;
      pros::delay(500);
    }
  }
}
