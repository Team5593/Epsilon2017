#include "BallPickupToggle.h"

BallPickupToggle::BallPickupToggle() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::ballPickup.get());
}

// Called just before this Command runs the first time
void BallPickupToggle::Initialize() {
	_isOn = !_isOn;
}

// Called repeatedly when this Command is scheduled to run
void BallPickupToggle::Execute() {
	ballPickup->Set(-_isOn);
	CommandBase::oi->_driverJoy.SetRumble(oi->_driverJoy.kRightRumble, _isOn * 0.5);
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
