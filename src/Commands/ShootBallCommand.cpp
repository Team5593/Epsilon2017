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
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::Shooter.get());
}

// Called just before this Command runs the first time
void ShootBallCommand::Initialize() {
	std::cout << "ShootBallCommand::Initialize." << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void ShootBallCommand::Execute() {
	std::cout << "ShootBallCommand::Execute." << std::endl;
	CommandBase::Shooter->Set(-0.95);
}

// Make this return true when this Command no longer needs to run execute()
bool ShootBallCommand::IsFinished() {
	// ToDo: There needs to be some timing factor that sets is finished to true after enough
	// time has passed for the shot to have been completed.
	return true;
}

// Called once after isFinished returns true
void ShootBallCommand::End() {
	std::cout << "ShootBallCommand::End." << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootBallCommand::Interrupted() {

}
