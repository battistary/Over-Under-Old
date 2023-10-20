#include "main.h"

// Helper functions
void setDrive(int left, int right) {
    driveLeft = left;
    driveRight = right;
}

void resetDriveEncoders() {
    driveLeftFront.tare_position();
    driveLeftBack.tare_position();
    driveRightFront.tare_position();
    driveRightBack.tare_position();
}

double avgDriveEncoderValue() {
    return (fabs(driveLeftFront.get_position()) +
    fabs(driveLeftBack.get_position()) +
    fabs(driveRightFront.get_position()) +
    fabs(driveRightBack.get_position())) / 4;
}

// Autonomous Driving Functions
void translate(double units, int voltage) {
    // Define a direction based on units provided
    int direction = fabs(units) / units; // Returns either 1 or -1
    // Reset motor encoders and gyro rotation
    resetDriveEncoders();
    imu.tare_rotation();
    // Drive forward until units are reached
    while( avgDriveEncoderValue() < fabs(units) ) {
        // Gyro correction if bot veers off path
        // If correction is too much, multiply gyro degrees by 0.75 or 0.5
        setDrive(voltage * direction - (imu.get_rotation() * 10), voltage * direction + (imu.get_rotation() * 10));
        pros::delay(10);
    }
    // Brief brake
    setDrive(-10 * direction, -10 * direction);
    pros::delay(50); // Calibrate to weight of our bot. ># -> Heavier bot, 50 is fairly light
    // Set drive back to neutral
    setDrive(0, 0);
}

void rotate(int degrees, int voltage) {
    // Define a direction based on the units provided
    int direction = 1;
    if ( degrees < imu.get_rotation() ) {
        direction = -1;
    }
    // Turn until units - 5 degrees are reached
    setDrive(voltage * direction, -voltage * direction);
    if ( direction == 1 ) {
        while ( imu.get_rotation() < degrees - 5 ) {
            pros::delay(10);
        }
    }
    else {
        while ( imu.get_rotation() > degrees + 5 ) {
            pros::delay(10);
        }
    }
    // Wait for robot to loose momentum before performing corrections
    setDrive(0, 0);
    pros::delay(100);
    if ( direction == 1 ) {
        // Correct for overshoot
        if ( imu.get_rotation() > degrees ) {
            setDrive(-30 * direction, 30 * direction);
            while ( imu.get_rotation() > degrees ) {
                pros::delay(10);
            }
        }
        // Correct for undershoot
        else if ( imu.get_rotation() < degrees ) {
            setDrive(30 * direction, -30 * direction);
            while ( imu.get_rotation() < degrees ) {
                pros::delay(10);
            }
        }
    }
    else {
        // Correct for overshoot
        if ( imu.get_rotation() > degrees ) {
            setDrive(-30 * direction, 30 * direction);
            while ( imu.get_rotation() < degrees ) {
                pros::delay(10);
            }
        }
        // Correct for undershoot
        else if ( imu.get_rotation() < degrees ) {
            setDrive(30 * direction, -30 * direction);
            while ( imu.get_rotation() > degrees ) {
                pros::delay(10);
            }
        }
    }
    // Reset drive to zero
    setDrive(0, 0);
    resetDriveEncoders();
}
