#include "BallPickupToggle.h"

BallPickupToggle::BallPickupToggle() {
	Requires(CommandBase::ballPickup.get());
}

// Called just before this Command runs the first time
void BallPickupToggle::Initialize() {
	std::cout << "BallPickupToggle::Initialize." << std::endl;
	_isOn = !_isOn; // Toggle the motor on or off
	_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void BallPickupToggle::Execute() {
	//std::cout << "BallPickupToggle::Execute." << std::endl;
	ballPickup->Set(PICKUP_SPEED * _isOn);

	CommandBase::oi->SetRumbleRight(_isOn * 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool BallPickupToggle::IsFinished() {
	return _isFinished;
}

// Called once after isFinished returns true
void BallPickupToggle::End() {
	std::cout << "BallPickupToggle::End." << std::endl;
	CommandBase::oi->SetRumbleRight(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallPickupToggle::Interrupted() {
	std::cout << "BallPickupToggle::Interrupted." << std::endl;
	_isFinished = true;
}
