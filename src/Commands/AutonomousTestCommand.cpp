#include "AutonomousTestCommand.h"

AutonomousTestCommand::AutonomousTestCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutonomousTestCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutonomousTestCommand::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousTestCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutonomousTestCommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousTestCommand::Interrupted() {

}
