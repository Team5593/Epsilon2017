// ============================================================================
// FileName: Robot.h
//
// Description:
// Header file for the main robot program.
//
// Author(s):
// Team 5593
//
// History:
// 27 Jan 2017	Team 5593	Created.
//
// License:
// Public Domain
// ============================================================================


#ifndef ROBOT_H_
#define ROBOT_H_

#include "WPILib.h"
#include "RobotMap.h"
#include "Commands/ShootBallCommand.h"
#include "Commands/AutoRotate.h"
#include "Commands/AutoMove.h"
#include "Commands/DeliverGear/DeliverGearCommandGroup.h"
#include "Commands/BallPickupToggle.h"

class Robot: public IterativeRobot {
public:

private:
	//LiveWindow * lw;

	void RobotInit();
	void DisabledInit();
	void AutonomousInit();
	void TeleopInit();
	void TestInit();

	void RobotPeriodic();
	void DisabledPeriodic();
	void AutonomousPeriodic();
	void TeleopPeriodic();
	void TestPeriodic();

	//Command * _autonomousCommand { nullptr };
	//SendableChooser *_chooser { nullptr };

	// Commands used in Test mode to verify operation.
	std::unique_ptr<ShootBallCommand> _shootBallCommand{ nullptr };
	std::unique_ptr<AutoRotate> _autoRotate{ nullptr };
	std::unique_ptr<AutoMove> _autoMove{ nullptr };
	std::unique_ptr<DeliverGearCommandGroup> _deliverGearCommandGroup { nullptr };
	std::unique_ptr<BallPickupToggle> _ballPickupToggle{ nullptr };
};

#endif /* ROBOT_H_ */
