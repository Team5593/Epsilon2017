#include "CommandBase.h"

#include <Commands/Scheduler.h>

// Initialize the static instances of each subsystems to nullptr.
std::unique_ptr<DriveTrain> CommandBase::driveTrain { nullptr };
std::unique_ptr<Shooter> CommandBase::shooter { nullptr };
std::unique_ptr<BallPickup> CommandBase::ballPickup { nullptr };
std::unique_ptr<CogPixy> CommandBase::cogPixy { nullptr };
std::unique_ptr<Lifter> CommandBase::lifter { nullptr };
std::unique_ptr<OI> CommandBase::oi { nullptr };

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {
}

void CommandBase::init()
{
	CommandBase::driveTrain.reset(new DriveTrain(DRIVETRAIN_LEFT_MOTOR, DRIVETRAIN_RIGHT_MOTOR, DRIVETRAIN_ENC_LEFT_A, DRIVETRAIN_ENC_LEFT_B, DRIVETRAIN_ENC_RIGHT_A, DRIVETRAIN_ENC_RIGHT_B, DRIVETRAIN_ANALOG_GYRO));
	CommandBase::shooter.reset(new Shooter(SHOOTER_TALON_PIN, 6));
	CommandBase::ballPickup.reset(new BallPickup(PICKUP_TALON));
	CommandBase::cogPixy.reset(new CogPixy());
	CommandBase::lifter.reset(new Lifter(LIFTER_SPARK_LEFT, LIFTER_SPARK_RIGHT));
	CommandBase::oi.reset(new OI(DRIVER_JOY_NUM));
}
