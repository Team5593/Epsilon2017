#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <RobotDrive.h>
#include <Encoder.h>
#include <AnalogGyro.h>
#include "RobotMap.h"

class DriveTrain : public Subsystem {

private:
	// DON'T initialize any objects here. The FPGA and other initialization tasks
	// may not have completed. Instead do the initialization in the class constructor.
	//frc::RobotDrive driveTrain{DRIVETRAIN_LEFT_MOTOR, DRIVETRAIN_LEFT_MOTOR};
	frc::RobotDrive _robotDrive;
	frc::Encoder _encLeft;
	frc::Encoder _encRight;
	frc::AnalogGyro _gyro;

public:
	DriveTrain(int leftMotorChannel, int rightMotorChannel, int encLeftChannelA, int encLeftChannelB, int encRightChannelA, int encRightChannelB, int analogGyroChannel);
	void InitDefaultCommand();
	void TankDrive(double left, double right);

	// Gyro
	void GyroCalibrate();
	void GyroReset();
	double GetGyroAngle();


	void Stop();
};

#endif  // DriveTrain_H
