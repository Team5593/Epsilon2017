#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <RobotDrive.h>

class DriveTrain : public Subsystem {
	frc::RobotDrive driveTrain{DRIVETRAIN_LEFT_MOTOR, DRIVETRAIN_LEFT_MOTOR};
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(double left, double right);
	void Stop();
};

#endif  // DriveTrain_H
