#include "AutoRotate.h"

AutoRotate::AutoRotate() {
	Requires(CommandBase::driveTrain.get());
}

// angle: The angle to rotate in degrees. A positive angle rotates right, negative rotates left.
void AutoRotate::Initialize(double angle) {
	std::cout << "AutoRotate::Initialize " << angle << " " << ((angle > 0) ? "right" : "left") << std::endl;
	_relativeAngle = driveTrain->GetGyroAngle() + angle;
}

// Called repeatedly when this Command is scheduled to run
void AutoRotate::Execute() {
	//if (_firstExecute) {
	//	driveTrain->GyroReset();
	//	_firstExecute = false;
	//}
	//std::cout << "AutoRotate::Execute " << driveTrain->GetGyroAngle() << std::endl;

	if (driveTrain->GetGyroAngle()<_relativeAngle) {
		driveTrain->TankDrive(_speed, -_speed);
	} else driveTrain->TankDrive(-_speed, _speed);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRotate::IsFinished() {
	return driveTrain->GetGyroAngle() <= _relativeAngle + 2 && driveTrain->GetGyroAngle() >= _relativeAngle - 2;
} //Robot within 2 degrees of desired angle

// Called once after isFinished returns true
void AutoRotate::End() {
	std::cout << "AutoRotate::End" << std::endl;
	driveTrain->TankDrive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRotate::Interrupted() {
	std::cout << "AutoRotate::Interrupted" << std::endl;
}
