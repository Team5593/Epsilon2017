#include "AutoMove.h"

AutoMove::AutoMove() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoMove::Initialize(double relativeDistance) {
	_relativeDistance = relativeDistance/(4* 3.14159)*250;
	driveTrain->EncResetAll();
}

// Called repeatedly when this Command is scheduled to run
void AutoMove::Execute() {
	_leftFinished=fabs(driveTrain->EncGetLeft()) >= fabs(_relativeDistance);
	_rightFinished=fabs(driveTrain->EncGetRight()) >= fabs(_relativeDistance);
	double proportion = (driveTrain-> EncGetLeft() - driveTrain-> EncGetRight()) / 250;
	int inverted = fabs(_relativeDistance) / _relativeDistance;

	//if (driveTrain->EncGetLeft()<_relativeDistance) {
	//		driveTrain->TankDrive(0.3*!_leftFinished/*+proportion*/, 0.3*!_rightFinished/*+proportion*/);
	//} else driveTrain->TankDrive(-0.5-proportion, -0.5-proportion);

	driveTrain->TankDrive(0.45*!_leftFinished*inverted-proportion, 0.45*!_rightFinished*inverted+proportion);


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
