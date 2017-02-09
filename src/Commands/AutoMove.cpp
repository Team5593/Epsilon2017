#include "AutoMove.h"

AutoMove::AutoMove() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoMove::Initialize(double relativeDistance, double speed) {
	_relativeDistance = relativeDistance/(4* 3.14159)*250;
	_speed = speed;
	driveTrain->EncResetAll();
	driveTrain->GyroReset();
}

void AutoMove::Initialize(double relativeDistance) {
	_relativeDistance = relativeDistance/(4* 3.14159)*250;
	driveTrain->EncResetAll();
	driveTrain->GyroReset();
}

// Called repeatedly when this Command is scheduled to run
void AutoMove::Execute() {
	_leftFinished=fabs(driveTrain->EncGetLeft()) >= fabs(_relativeDistance);
	_rightFinished=fabs(driveTrain->EncGetRight()) >= fabs(_relativeDistance);
	double proportion = (driveTrain->GetGyroAngle()) / 180;
	int inverted = fabs(_relativeDistance) / _relativeDistance;

	driveTrain->TankDrive(_speed*!_leftFinished*inverted-proportion, _speed*!_rightFinished*inverted+proportion);


}

// Make this return true when this Command no longer needs to run execute()
bool AutoMove::IsFinished() {
	return _rightFinished && _leftFinished;
}

// Called once after isFinished returns true
void AutoMove::End() {
	driveTrain->TankDrive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoMove::Interrupted() {

}
