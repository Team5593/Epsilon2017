#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain(int leftMotorChannel, int rightMotorChannel) : Subsystem("DriveTrain"),
 _robotDrive(leftMotorChannel, rightMotorChannel)
{

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::TankDrive(double left, double right) {
	_robotDrive.TankDrive(left*DRIVETRAIN_MAX_SPEED, right*DRIVETRAIN_MAX_SPEED);
}

void DriveTrain::Stop() {
	_robotDrive.TankDrive(0.0, 0.0);
}
