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
	Requires(CommandBase::shooter.get());
}

void ShootBallCommand::Initialize() {
	std::cout << "ShootBallCommand::Initialize." << std::endl;
	_isOn = !_isOn; // Toggle the motor on or off
	_isFinished = false;
}

void ShootBallCommand::Execute() {

	//std::cout << "ShootBallCommand::Execute." << std::endl;
	if (_isOn) {
		CommandBase::shooter->Enable();
	}
	else {
		CommandBase::shooter->Disable();
	}

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
}
