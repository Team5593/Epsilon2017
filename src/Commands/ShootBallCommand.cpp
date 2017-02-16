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
	//_isOn = !_isOn; // ToDo: I couldn't understand what this was for. If required put it back but please add a comment as to the purpose.
	_isFinished = false;
}

void ShootBallCommand::Execute() {
	//std::cout << "ShootBallCommand::Execute." << std::endl;
	CommandBase::Shooter->SetShooter(-0.90*_isOn);
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
