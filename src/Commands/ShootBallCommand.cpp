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
	_isOn = !_isOn;
	CommandBase::shooter->Enable();
	CommandBase::oi->SetRumbleLeft(0.5*_isOn);
}

void ShootBallCommand::Execute() {
	std::cout << "ShootBallCommand::Execute." << std::endl;

}

bool ShootBallCommand::IsFinished() {
	return false;
}

void ShootBallCommand::End() {
	std::cout << "ShootBallCommand::End." << std::endl;
	CommandBase::oi->SetRumbleLeft(0.0);
	CommandBase::shooter->Disable();
	//CommandBase::shooter->Disable();
}

void ShootBallCommand::Interrupted() {
	std::cout << "ShootBallCommand::Interrupted." << std::endl;
	if (!_isOn) {
		End();
	}
}
