#include "DriveTrain.h"
#include "../Commands/Drive.h"

DriveTrain::DriveTrain(int leftMotorChannel, int rightMotorChannel, int encLeftChannelA, int encLeftChannelB, int encRightChannelA, int encRightChannelB, int analogGyroChannel) : Subsystem("DriveTrain"),
 _robotDrive(leftMotorChannel, rightMotorChannel),
 _encLeft(encLeftChannelA, encLeftChannelB),
 _encRight(encRightChannelA, encRightChannelB),
 _gyro(analogGyroChannel)
{

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
}

void DriveTrain::TankDrive(double left, double right) {
	_robotDrive.TankDrive(left, right);
}

void DriveTrain::GyroCalibrate() {
	_gyro.Calibrate();
}

void DriveTrain::GyroReset() {
	_gyro.Reset();
}

double DriveTrain::GetGyroAngle() {
	return _gyro.GetAngle();
}

void DriveTrain::Stop() {
	_robotDrive.TankDrive(0.0, 0.0);
}
