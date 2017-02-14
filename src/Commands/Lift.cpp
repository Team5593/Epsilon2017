#include "Lift.h"

Lift::Lift() {
	Requires(CommandBase::lifter.get());
}

// Called just before this Command runs the first time
void Lift::Initialize() {
	_isOn = !_isOn;
}

// Called repeatedly when this Command is scheduled to run
void Lift::Execute() {
	lifter->Set(_isOn);
}

// Make this return true when this Command no longer needs to run execute()
bool Lift::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Lift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lift::Interrupted() {

}
