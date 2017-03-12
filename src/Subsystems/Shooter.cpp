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

Shooter::Shooter(int shooterChannel, int feederChannel) : frc::PIDSubsystem("Shooter", kP_real, kI_real, kD_real),
	_shooterTalon{shooterChannel},
	_feederTalon{feederChannel},
	_shooterEncoder{frc::I2C::kOnboard, 0x08}
{

}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double Shooter::ReturnPIDInput() {
	//return -GetEncoder() / SHOOTER_MAX_RPM;
	return 0.95; // Bodge value
}

void Shooter::UsePIDOutput(double d) {
	_shooterTalon.PIDWrite(d);
	_shooterTalon.Set(FEEDER_SPEED * d);
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


