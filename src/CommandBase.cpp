#include "CommandBase.h"

#include <Commands/Scheduler.h>

// Initialize the static instances of each subsystems to nullptr. If an attempt is
// made to create subsystem objects there are almost always problems with the roboRio
// not being correctly initialized. Instead initialize the real objects in the init method.
std::unique_ptr<DriveTrain> CommandBase::driveTrain { nullptr };
std::unique_ptr<ShooterSubsystem> CommandBase::Shooter { nullptr };
std::unique_ptr<BallPickup> CommandBase::ballPickup { nullptr };
std::unique_ptr<OI> CommandBase::oi { nullptr };

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {
}

void CommandBase::init()
{
	CommandBase::driveTrain.reset(new DriveTrain(DRIVETRAIN_LEFT_MOTOR, DRIVETRAIN_RIGHT_MOTOR, DRIVETRAIN_ENC_LEFT_A, DRIVETRAIN_ENC_LEFT_B, DRIVETRAIN_ENC_RIGHT_A, DRIVETRAIN_ENC_RIGHT_B, DRIVETRAIN_ANALOG_GYRO));
	CommandBase::Shooter.reset(new ShooterSubsystem(SHOOTER_TALON_PIN, 6));
	CommandBase::ballPickup.reset(new BallPickup(PICKUP_TALON));
	CommandBase::oi.reset(new OI(DRIVER_JOY_NUM));
}
