// ============================================================================
// FileName: ShooterSubsystem.h
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

#ifndef ShooterSubsystem_H
#define ShooterSubsystem_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class ShooterSubsystem : public Subsystem {
private:
	Talon _shooterTalon;
	Talon _feederTalon;

public:
	ShooterSubsystem(int shooterChannel, int feederChannel);
	void InitDefaultCommand();
	void SetShooter(double speed);
	void SetFeeder(double speed);
};

#endif  // ShooterSubsystem_H
