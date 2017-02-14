#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <RobotDrive.h>
#include <Encoder.h>
#include <AnalogGyro.h>
#include <Ultrasonic.h>
#include "RobotMap.h"

class DriveTrain : public frc::Subsystem {

private:
	// DON'T initialize any objects here. The FPGA and other initialization tasks
	// may not have completed. Instead do the initialization in the class constructor.
	//frc::RobotDrive driveTrain{DRIVETRAIN_LEFT_MOTOR, DRIVETRAIN_LEFT_MOTOR};
	frc::RobotDrive _robotDrive;
	frc::Encoder _encLeft;
	frc::Encoder _encRight;
	frc::AnalogGyro _gyro;

	double _distancePerPulse = 4 * 3.14159 / 250;

public:
	DriveTrain(int leftMotorChannel, int rightMotorChannel, int encLeftChannelA, int encLeftChannelB, int encRightChannelA, int encRightChannelB, int analogGyroChannel, int ultraLeftChannel, int ultraRightChannel);
	void InitDefaultCommand();
	void TankDrive(double left, double right);
	void Stop();

	// Gyro
	void GyroCalibrate();
	void GyroReset();
	double GetGyroAngle();
	// Encoders
	double EncGetLeft();
	double EncGetRight();
	void EncResetLeft();
	void EncResetRight();
	void EncResetAll();
	// Ultraonics
	double GetUltraFrontLeft();
	double GetUltraFrontRight();
};

#endif  // DriveTrain_H
