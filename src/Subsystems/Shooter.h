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

class Shooter : public Subsystem {
private:
	Talon _shooterTalon;
	Talon _feederTalon;
	I2C _shooterEncoder;

	double _shooterSpeed = SHOOTER_SPEED;
	double _feederSpeed = FEEDER_SPEED;

public:
	Shooter(int shooterChannel, int feederChannel);
	void InitDefaultCommand();
	void Enable();
	void Disable();
	void SetShooterSpeed(double speed);
	void SetFeederSpeed(double speed);
	int GetEncoder();
};

#endif  // Shooter_H
