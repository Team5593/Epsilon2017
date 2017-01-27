#include "CommandBase.h"

#include <Commands/Scheduler.h>


// Initialize the static instances of each subsystems to nullptr. If an attempt is
// made to create subsystem objects there are almost always problems with the roboRio
// not being correctly initialised. Instead initialise the real objects in the init method.
std::unique_ptr<DriveTrain> CommandBase::driveTrain { nullptr };
std::unique_ptr<OI> CommandBase::oi { nullptr };

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init()
{
	CommandBase::driveTrain.reset(new DriveTrain(DRIVETRAIN_LEFT_MOTOR, DRIVETRAIN_RIGHT_MOTOR));
	CommandBase::oi.reset(new OI());
}
