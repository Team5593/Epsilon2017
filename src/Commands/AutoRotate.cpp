#include "AutoRotate.h"

AutoRotate::AutoRotate(double relativeAngle): _relativeAngle(relativeAngle) {

}

// Called just before this Command runs the first time
void AutoRotate::Initialize() {
	std::cout << "AutoRotate::Initialize" << std::endl;
	driveTrain->GyroReset();
}

// Called repeatedly when this Command is scheduled to run
void AutoRotate::Execute() {
	std::cout << "AutoRotate::Execute" << std::endl;
	if (driveTrain->GetGyroAngle()<_relativeAngle) {
		driveTrain->TankDrive(0.5, -0.5);
	} else driveTrain->TankDrive(-0.5, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRotate::IsFinished() {
	return driveTrain->GetGyroAngle() <= _relativeAngle+2 && driveTrain->GetGyroAngle() >= _relativeAngle-2;
} //Robot within 2 degrees of desired angle

// Called once after isFinished returns true
void AutoRotate::End() {
	driveTrain->TankDrive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRotate::Interrupted() {

}
