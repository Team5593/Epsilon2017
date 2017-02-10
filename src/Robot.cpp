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

#include "Robot.h"

// Provide for initialization at robot power-on.
void Robot::RobotInit() {
	std::cout << "RobotInit" << std::endl;

	CommandBase::init();

	_shootBallCommand = std::make_unique<ShootBallCommand>();
	_autoRotate = std::make_unique<AutoRotate>();
	_autoMove = std::make_unique<AutoMove>();
	_ballPickupToggle = std::make_unique<BallPickupToggle>();
	_deliverGearCommandGroup = std::make_unique<DeliverGearCommandGroup>();
}


// Runs all of the time (including during disabled methods)
void Robot::RobotPeriodic() {
	//std::cout << "RobotPeriodic" << std::endl;
}

// Run once when robot enters disabled mode
void Robot::DisabledInit() {
	std::cout << "DisabledInit" << std::endl;
	CommandBase::driveTrain->GyroCalibrate();
}

// Runs when robot is disabled
void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

// Run once when robot enters autonomous mode
void Robot::AutonomousInit() {
	std::cout << "AutonomousInit" << std::endl;

	std::vector<std::pair<AutoCommand_t, double>> commandVec;

	commandVec.push_back({AutoCommand_t::AutoMoveCommand, 73}); 	// Move away from wall
	commandVec.push_back({AutoCommand_t::AutoRotateCommand, -30}); 	// Turn parallel to the peg wall
	commandVec.push_back({AutoCommand_t::AutoMoveCommand, 20});		// Move inline with peg
	commandVec.push_back({AutoCommand_t::AutoRotateCommand, 90}); 	// Turn facing the peg

	_deliverGearCommandGroup->Initialize(commandVec);

	_deliverGearCommandGroup->Start();
}

// Runs when robot is in autonomous mode
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

// Run once when robot enters teleop mode
void Robot::TeleopInit() {
	std::cout << "TeleopInit" << std::endl;


	// Stop autonomous commands
	//if (autonomousCommand != NULL) {
	//	autonomousCommand->Cancel();
	//}
	CommandBase::oi->SetButtonPressedCommand( 1, (Command *)_shootBallCommand.get());
	CommandBase::oi->SetButtonPressedCommand( 2, (Command *)_ballPickupToggle.get());

}

// Runs when robot is in teleop mode
void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	LiveWindow::GetInstance()->Run();
	Scheduler->Set
}

// Run once when robot enters test mode
void Robot::TestInit()
{
	std::cout << "TestInit" << std::endl;

}

// Runs when robot is in test mode
void Robot::TestPeriodic() {
	// Scheduler doesn't get enabled by default in Test mode so if you want to test commands enable it.
	Scheduler::GetInstance()->Run();
	LiveWindow::GetInstance()->Run();
}

// Macro that supplies the main function entry point for the robot program (note macros aren't cool
// don't write them).
START_ROBOT_CLASS(Robot)
