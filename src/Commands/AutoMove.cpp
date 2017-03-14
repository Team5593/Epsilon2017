#include "AutoMove.h"

AutoMove::AutoMove() {
	Requires(CommandBase::driveTrain.get());
}

// Called just before this Command runs the first time
void AutoMove::Initialize(double distance) {
	_relativeDistance += ((distance/(4 * 3.14159)) * 250);
	//driveTrain->EncResetAll();
	//driveTrain->GyroReset();
}

// Called repeatedly when this Command is scheduled to run
void AutoMove::Execute() {
	if (_firstExecute) {
		driveTrain->EncResetAll();
		driveTrain->GyroReset();
		_firstExecute = false;
	}
	
	//std::cout << "AutoMove::Execute " << driveTrain->EncGetLeft() << " " << driveTrain->EncGetRight() << std::endl;

	_leftFinished=fabs(driveTrain->EncGetLeft()) >= fabs(_relativeDistance);
	_rightFinished=fabs(driveTrain->EncGetRight()) >= fabs(_relativeDistance);
	double proportion = (driveTrain->GetGyroAngle()) / 90;
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
	driveTrain->TankDrive(0.0, 0.0);
}

