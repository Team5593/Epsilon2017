#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>
#include <Commands/Command.h>
#include "Subsystems/DriveTrain.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Subsystems/BallPickup.h"
#include "Subsystems/CogPixy.h"
#include "Subsystems/Lifter.h"
#include "OI.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void init();

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DriveTrain> driveTrain;
	static std::unique_ptr<ShooterSubsystem> Shooter;
	static std::unique_ptr<BallPickup> ballPickup;
	static std::unique_ptr<CogPixy> cogPixy;
	static std::unique_ptr<Lifter> lifter;
	static std::unique_ptr<OI> oi;
};

#endif  // COMMAND_BASE_H
