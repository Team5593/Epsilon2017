#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <RobotDrive.h>
#include "RobotMap.h"

class DriveTrain : public Subsystem {

private:
	// DON'T intialise any objects here. The FPGA and other initialisation tasks
	// may not have been complete. Instead do the initialisation in the class constructor.
	//frc::RobotDrive driveTrain{DRIVETRAIN_LEFT_MOTOR, DRIVETRAIN_LEFT_MOTOR};
	frc::RobotDrive _robotDrive;

public:
	DriveTrain(int leftMotorChannel, int rightMotorChannel);
	void InitDefaultCommand();
	void TankDrive(double left, double right);
	void Stop();
};

#endif  // DriveTrain_H
