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
	//std::cout << "ShootBallCommand::Initialize." << std::endl;
	_isOn = !_isOn;
}

void ShootBallCommand::Execute() {
	//std::cout << "ShootBallCommand::Execute." << std::endl;
	CommandBase::Shooter->SetShooter(-0.90*_isOn);
	CommandBase::Shooter->SetFeeder(1.0*_isOn);
	CommandBase::oi->SetRumbleLeft(_isOn * 0.5);
}

bool ShootBallCommand::IsFinished() {
	return false;
}

void ShootBallCommand::End() {
	std::cout << "ShootBallCommand::End." << std::endl;
}

void ShootBallCommand::Interrupted() {

}
