#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>
#include <Commands/Command.h>
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/BallPickup.h"
#include "Subsystems/CogPixy.h"
#include "Subsystems/Lifter.h"
#include "OI.h"

// CommandBase is the base for all commands
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void init();

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DriveTrain> driveTrain;
	static std::unique_ptr<Shooter> shooter;
	static std::unique_ptr<BallPickup> ballPickup;
	static std::unique_ptr<CogPixy> cogPixy;
	static std::unique_ptr<Lifter> lifter;
	static std::unique_ptr<OI> oi;
};

#endif  // COMMAND_BASE_H
