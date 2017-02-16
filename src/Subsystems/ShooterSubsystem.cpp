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

ShooterSubsystem::ShooterSubsystem(int shooterChannel, int feederChannel) : Subsystem("ShooterSubsystem"),
	_shooterTalon{shooterChannel},
	_feederTalon{feederChannel},
	_shooterEncoder{I2C::kOnboard, 0x08}
{

}

void ShooterSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void ShooterSubsystem::SetShooter(double speed) {
	_shooterTalon.Set(-speed);
}

void ShooterSubsystem::SetFeeder(double speed) {
	_feederTalon.Set(speed);
}

int ShooterSubsystem::GetEncoder() {
	uint8_t val[1];
	_shooterEncoder.ReadOnly( 1, val);
	//std::cout << "Encoder Shooter: " << int(val[0]) << std::endl;
	return val[0] * 240;
}


