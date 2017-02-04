#include <Commands/DeliverGear/DriveSetDistanceCommand.h>

DriveSetDistanceCommand::DriveSetDistanceCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveSetDistanceCommand::Initialize(double distanceCentimeters) {
	// ToDo: Whatever needs to be done to initialise the robot for the drive.
}

// Called repeatedly when this Command is scheduled to run
void DriveSetDistanceCommand::Execute() {
	// ToDo: Whatever needs to be done to drive forwards the requested distance.
}

// Make this return true when this Command no longer needs to run execute()
bool DriveSetDistanceCommand::IsFinished() {
	// ToDo: Whatever needs to be done to detect the robot has driven forwards the requested distance.
	return false;
}

// Called once after isFinished returns true
void DriveSetDistanceCommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveSetDistanceCommand::Interrupted() {

}
