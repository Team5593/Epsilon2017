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
}

// This function is called each time a new packet is received from the driver station
// INCLUDING when the robot is disabled.
void Robot::RobotPeriodic() {
	std::cout << "RobotPeriodic" << std::endl;
}

// This function is called once each time the robot enters Disabled mode.
// You can use it to reset any subsystem information you want to clear when
// the robot is disabled.
void Robot::DisabledInit() {

}

// When the robot is in Disabled this method is called each time a new packet is received from the driver station.
void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

// Called each and every time autonomous is entered from another mode.
void Robot::AutonomousInit() {
	//autonomousCommand = (Command *) chooser->GetSelected();
	//autonomousCommand->Start();
}

// When the robot is in Autonomous mode this method is called each time a new packet is received from the driver station.
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

// Called each and every time teleop is entered from another mode.
void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	//if (autonomousCommand != NULL) {
	//	autonomousCommand->Cancel();
	//}
}

// When the robot is in Teleop mode this method is called each time a new packet is received from the driver station.
void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

// Called each and every time test is entered from another mode.
void Robot::TestInit()
{
	// Scheduler doesn't get enabled by default in Test mode so if you want to test commands enable it.
	Scheduler::GetInstance()->SetEnabled(true);
}

// When the robot is in Test mode this method is called each time a new packet is received from the driver station.
void Robot::TestPeriodic() {
	// Scheduler doesn't get enabled by default in Test mode so if you want to test commands enable it.
	Scheduler::GetInstance()->Run();
	LiveWindow::GetInstance()->Run();
}

// Macro that supplies the main function entry point for the robot program (note macros aren't cool
// don't write them).
START_ROBOT_CLASS(Robot)
