// ============================================================================
// FileName: Shooter.h
//
// Description:
// Subsystem for a 2017 FRC command based robot that shoots balls into the boiler.
//
// Author(s):
// Team 5593
//
// History:
// 28 Jan 2017	Team 5593	Created.
//
// License:
// Public Domain
// ============================================================================

#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "RobotMap.h"
#include <Commands/PIDSubsystem.h>

class Shooter : public frc::PIDSubsystem {
private:
	Talon _shooterTalon;
	Talon _feederTalon;
	I2C _shooterEncoder;

	double _shooterSpeed = SHOOTER_DEFAULT_RPM;
	double _feederSpeed = FEEDER_SPEED;

	static constexpr double kP_real = 4;
	static constexpr double kI_real = 0.005;
	static constexpr double kD_real = 4;

public:
	Shooter(int shooterChannel, int feederChannel);
	void InitDefaultCommand();
	// PID
	double ReturnPIDInput();
	void UsePIDOutput(double d);

	void SetFeederSpeed(double speed);
	int GetEncoder();
};

#endif  // Shooter_H
