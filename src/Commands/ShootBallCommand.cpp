// ============================================================================
// FileName: ShooterBallCommand.cpp
//
// Description:
// See header.
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

#include "ShootBallCommand.h"

ShootBallCommand::ShootBallCommand() {
	Requires(CommandBase::Shooter.get());
}

void ShootBallCommand::Initialize() {
	std::cout << "ShootBallCommand::Initialize." << std::endl;
	_isOn = !_isOn; // Toggle the motor on or off
	_isFinished = false;
}

void ShootBallCommand::Execute() {

	//std::cout << "ShootBallCommand::Execute." << std::endl;
	CommandBase::Shooter->SetShooter(SHOOTER_SPEED*_isOn);
	CommandBase::Shooter->SetFeeder(1.0*_isOn);
	CommandBase::oi->SetRumbleLeft(_isOn * 0.5);
}

bool ShootBallCommand::IsFinished() {
	return _isFinished;
}

void ShootBallCommand::End() {
	std::cout << "ShootBallCommand::End." << std::endl;
	CommandBase::oi->SetRumbleLeft(0.0);
}

void ShootBallCommand::Interrupted() {
	std::cout << "ShootBallCommand::Interrupted." << std::endl;
	 _isFinished = true;
	 CommandBase::oi->SetRumbleLeft(0.0);
}
