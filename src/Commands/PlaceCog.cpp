#include "PlaceCog.h"

PlaceCog::PlaceCog() {
	Requires(CommandBase::cogPixy.get());
	Requires(CommandBase::driveTrain.get());
}

// Called just before this Command runs the first time
void PlaceCog::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PlaceCog::Execute() {
	double speed = -0.45;
	double heading = (cogPixy->GetX() - 159.5) / (319);
	std::cout << heading << std::endl;
	if (heading < 0) {
		driveTrain->TankDrive(speed - fabs(heading), speed);
	}
	else {
		driveTrain->TankDrive(speed, speed - fabs(heading));
	}

}

// Make this return true when this Command no longer needs to run execute()
bool PlaceCog::IsFinished() {
	return cogPixy->GetWidth() > 40;
}

// Called once after isFinished returns true
void PlaceCog::End() {
	driveTrain->TankDrive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PlaceCog::Interrupted() {
	End();
}
