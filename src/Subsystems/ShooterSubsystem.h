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

public:
	ShooterSubsystem(int talonShooterPin);
	void InitDefaultCommand();
	void ActivateShooter(int milliseconds);
};

#endif  // ShooterSubsystem_H
