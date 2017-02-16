#include "Lift.h"

Lift::Lift() {
	Requires(CommandBase::lifter.get());
}

// Called just before this Command runs the first time
void Lift::Initialize() {
	std::cout << "Lift::Initialize." << std::endl;
	//_isOn = !_isOn; // ToDo: I couldn't understand what this was for. If required put it back but please add a comment as to the purpose.
	_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void Lift::Execute() {
	//std::cout << "Lift::Execute." << std::endl;
	lifter->Set(_isOn);
}

// Make this return true when this Command no longer needs to run execute()
bool Lift::IsFinished() {
	return _isFinished;
}

// Called once after isFinished returns true
void Lift::End() {
	std::cout << "Lift::End." << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lift::Interrupted() {
	std::cout << "Lift::Interrupted." << std::endl;
	_isFinished = true;
}
