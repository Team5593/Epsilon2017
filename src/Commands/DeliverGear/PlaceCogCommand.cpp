// ============================================================================
// FileName: PlaceCogCommand.cpp
//
// Description:
// See header.
//
// Author(s):
// Team 5593
//
// History:
// 04 Feb 2017	Team 5593	Created.
//
// License:
// Public Domain
// ============================================================================

#include "PlaceCogCommand.h"

PlaceCogCommand::PlaceCogCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void PlaceCogCommand::Initialize() {
	// ToDo: Whatever needs to happen to get the cameras ready to position the robot to get the cog delivered.
}

// Called repeatedly when this Command is scheduled to run
void PlaceCogCommand::Execute() {
	// ToDo: Whatever needs to happen to take the input from the cameras and adjust the robot's position to get the cog delivered.
}

// Make this return true when this Command no longer needs to run execute()
bool PlaceCogCommand::IsFinished() {
	// ToDo: Whatever needs to happen to detect that the cog has been successfully delivered.
	return false;
}

// Called once after isFinished returns true
void PlaceCogCommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PlaceCogCommand::Interrupted() {

}
