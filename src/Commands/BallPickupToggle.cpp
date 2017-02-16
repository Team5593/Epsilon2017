#include "BallPickupToggle.h"

BallPickupToggle::BallPickupToggle() {
	Requires(CommandBase::ballPickup.get());
}

// Called just before this Command runs the first time
void BallPickupToggle::Initialize() {
	std::cout << "BallPickupToggle::Initialize." << std::endl;
	//_isOn = !_isOn; // ToDo: I couldn't understand what this was for. If required put it back but please add a comment as to the purpose.
	_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void BallPickupToggle::Execute() {
	//std::cout << "BallPickupToggle::Execute." << std::endl;
	ballPickup->Set(-_isOn);
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
	CommandBase::oi->SetRumbleRight(0.0);
	_isFinished = true;
}
