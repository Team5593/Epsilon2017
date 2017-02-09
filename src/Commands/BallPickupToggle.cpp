#include "BallPickupToggle.h"

BallPickupToggle::BallPickupToggle() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void BallPickupToggle::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void BallPickupToggle::Execute() {
	ballPickup->Set(-oi->_driverJoy.GetRawButton(2));
}

// Make this return true when this Command no longer needs to run execute()
bool BallPickupToggle::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void BallPickupToggle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallPickupToggle::Interrupted() {

}
