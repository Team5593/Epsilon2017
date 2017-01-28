#include "Drive.h"

Drive::Drive() {
	Requires(CommandBase::driveTrain.get());
}

// Called just before this Command runs the first time
void Drive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	if (_altButtonLastState == false and oi->GetAltSpeedButton() == true) {
		_altSpeedState = !_altSpeedState;
	}

	double speed;
	if (_altSpeedState) {
		speed = DRIVETRAIN_ALT_MULTIPLIER;
	}
	else {
		speed = DRIVETRAIN_DEFAULT_MULTIPLIER;
	}
	double forwardSpeed = -oi->GetThrottleAxis()*speed;
	double headingAngle = oi->GetHeadingAxis()*speed;

	if (fabs(headingAngle) <= 0.2) headingAngle = 0; // Deadzone TODO: create and convert to some kind of 'deadzone' function

	driveTrain->TankDrive(forwardSpeed+headingAngle, forwardSpeed-headingAngle);

	//Robot::drivetrain->Drive(Robot::oi->GetJoystick());
}

// isFinished - Our isFinished method always returns false meaning this command never completes on it's own.
// The reason we do this is that this command will be set as the default command for the subsystem.
// This means that whenever the subsystem is not running another command, it will run this command.
// If any other command is scheduled it will interrupt this command, then return to this command when the other command completes.
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
	End();
}
