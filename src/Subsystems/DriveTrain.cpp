#include "DriveTrain.h"
#include "../Commands/Drive.h"

DriveTrain::DriveTrain(int leftMotorChannel, int rightMotorChannel) : Subsystem("DriveTrain"),
 _robotDrive(leftMotorChannel, rightMotorChannel)
{

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
}

void DriveTrain::TankDrive(double left, double right) {
	_robotDrive.TankDrive(left, right);
}

void DriveTrain::Stop() {
	_robotDrive.TankDrive(0.0, 0.0);
}
