#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::TankDrive(double left, double right) {
	driveTrain.TankDrive(left*DRIVETRAIN_MAX_SPEED, right*DRIVETRAIN_MAX_SPEED);
}

void DriveTrain::Stop() {
	driveTrain.TankDrive(0.0, 0.0);
}
