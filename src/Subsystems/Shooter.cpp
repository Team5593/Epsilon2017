// ============================================================================
// FileName: Shooter.cpp
//
// Description:
// Implementation for Shooter class. See header for full description.
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

#include "Shooter.h"

Shooter::Shooter(int shooterChannel, int feederChannel) : Subsystem("Shooter"),
	_shooterTalon{shooterChannel},
	_feederTalon{feederChannel},
	_shooterEncoder{frc::I2C::kOnboard, 0x08}
{

}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Shooter::Enable() {
	_shooterTalon.Set(_shooterSpeed);
	_feederTalon.Set(_feederSpeed);
}

void Shooter::Disable() {
	_shooterTalon.Set(0.0);
	_feederTalon.Set(0.0);
}

void Shooter::SetShooterSpeed(double speed) {
	_shooterSpeed = speed;
}

void Shooter::SetFeederSpeed(double speed) {
	_feederSpeed = speed;
}

int Shooter::GetEncoder() {
	uint8_t val[1];
	_shooterEncoder.ReadOnly( 1, val);
	//std::cout << "Encoder Shooter: " << int(val[0]) << std::endl;
	return val[0] * 240;
}


