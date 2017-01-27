#include "Drive.h"

Drive::Drive() {
	//Requires(CommandBase::driveTrain);
}

// Called just before this Command runs the first time
void Drive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	double forwardSpeed = -oi->GetThrottleAxis(DRIVER_JOY_NUM);
	double headingAngle = oi->GetHeadingAxis(DRIVER_JOY_NUM);

	if (fabs(headingAngle) <= 0.2) headingAngle = 0; // Deadzone TODO: create and convert to some kind of 'deadzone' function

	driveTrain->TankDrive(forwardSpeed+headingAngle, forwardSpeed-headingAngle);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	driveTrain->TankDrive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
