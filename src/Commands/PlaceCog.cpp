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
	ultraLeftFinished = driveTrain->GetUltraFrontLeft() < 4;
	ultraRightFinished = driveTrain->GetUltraFrontRight() < 4;
	double speed = 0.5;
	double heading = cogPixy->GetX() / 50;
	if (!ultraLeftFinished and !ultraRightFinished) {
		driveTrain->TankDrive(speed + heading, speed - heading);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool PlaceCog::IsFinished() {
	return ultraLeftFinished and ultraRightFinished;
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
