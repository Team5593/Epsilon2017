#include "Drive.h"

Drive::Drive() {
	Requires(CommandBase::driveTrain.get());
}

// Called just before this Command runs the first time
void Drive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	double speed = DRIVETRAIN_DEFAULT_SPEED+(oi->GetSpeedAxis() * (DRIVETRAIN_SHIFT_SPEED - DRIVETRAIN_DEFAULT_SPEED));
	double forwardSpeed = -oi->GetThrottleAxis();
	double heading = oi->GetHeadingAxis();

	if (fabs(heading) <= 0.2) heading = 0;
	driveTrain->TankDrive((forwardSpeed+heading)*speed, (forwardSpeed-heading)*speed);
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
