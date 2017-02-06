// ============================================================================
// FileName: ShooterSubsystem.cpp
//
// Description:
// Implementation for ShooterSubsystem class. See header for full description.
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

#include "ShooterSubsystem.h"

ShooterSubsystem::ShooterSubsystem(int talonShooterPin) : Subsystem("ExampleSubsystem"),
	_shooterTalon{talonShooterPin}
{

}

void ShooterSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// This method activates the shooter's talon motor controller for a set
// number of milliseconds. The idea is that it can be pre-determined how many
// milliseconds the motor needs to be activated to fire a single ball and thereby
// set the parameter based on the number of balls to shoot.
void ShooterSubsystem::ActivateShooter(int milliseconds) {
	// ToDo
}
