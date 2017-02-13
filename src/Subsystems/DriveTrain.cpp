#include "DriveTrain.h"
#include "../Commands/Drive.h"

DriveTrain::DriveTrain(int leftMotorChannel, int rightMotorChannel, int encLeftChannelA, int encLeftChannelB, int encRightChannelA, int encRightChannelB, int analogGyroChannel, int ultraLeftChannel, int ultraRightChannel) :
	frc::Subsystem("DriveTrain"),
	_robotDrive(leftMotorChannel, rightMotorChannel),
	_encLeft(encLeftChannelA, encLeftChannelB),
	_encRight(encRightChannelA, encRightChannelB),
	_gyro(analogGyroChannel),
	_ultraFrontLeft(ultraLeftChannel, 1),
	_ultraFrontRight(ultraRightChannel, 1)
{
	_encLeft.SetDistancePerPulse(_distancePerPulse);
	_encLeft.SetReverseDirection(true);
	_encRight.SetDistancePerPulse(_distancePerPulse);
	_robotDrive.SetExpiration(0.1);
	_robotDrive.SetSafetyEnabled(false);
	_ultraFrontLeft.SetDistanceUnits(_ultraFrontLeft.kInches);
	_ultraFrontRight.SetDistanceUnits(_ultraFrontRight.kInches);
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

void DriveTrain::GyroCalibrate() {
	_gyro.Calibrate();
}

void DriveTrain::GyroReset() {
	_gyro.Reset();
}

double DriveTrain::GetGyroAngle() {
	return _gyro.GetAngle();
}

double DriveTrain::EncGetLeft(){
	return _encLeft.Get();
}

double DriveTrain::EncGetRight(){
	return _encRight.Get();
}

void DriveTrain::EncResetLeft(){
	_encLeft.Reset();
}

void DriveTrain::EncResetRight(){
	_encRight.Reset();
}

void DriveTrain::EncResetAll(){
	EncResetLeft();
	EncResetRight();
}

double DriveTrain::GetUltraFrontLeft() {
	return _ultraFrontLeft.GetRangeInches();
}

double DriveTrain::GetUltraFrontRight() {
	return _ultraFrontRight.GetRangeInches();
}
