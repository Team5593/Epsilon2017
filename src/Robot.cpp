// ============================================================================
// FileName: Robot.cpp
//
// Description:
// Implementation file for the main robot program. The functions employed in this
// class are tightly coupled to the FRC Driver Station. The program does nothing useful
// until the "Enable" button for one of the modes (TeleOperated, Autonomous, Practice
// or Test) on the Driver Station is pressed.
//
// Author(s):
// Team 5593
//
// History:
// 13 Jan 2017	Team 5593	Created.
//
// License:
// Public Domain
// ============================================================================


#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Commands/ExampleCommand.h"
#include "CommandBase.h"

// Sensor Includes
#include <Pixy/PixyI2C.h>

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() override {

	}

	void RobotPeriodic() override {
		int i = pixy->GetBlocks();
		SmartDashboard::PutNumber("Blocks", i);
	}

	void DisabledInit() override {

	}

	void DisabledPeriodic() override {

	}

	void AutonomousInit() override {

	}

	void AutonomousPeriodic() override {

	}

	void TeleopInit() override {

	}

	void TeleopPeriodic() override {

	}

	void TestPeriodic() override {

	}

private:
	//PixyI2C *pixy = new PixyI2C(0x54, I2C::Port::kOnboard); // Example Constructor
};

// Macro that supplies the main function entry point for the robot program (note macros aren't cool
// don't write them).
START_ROBOT_CLASS(Robot)
