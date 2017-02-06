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
}

// This function is called each time a new packet is received from the driver station
// INCLUDING when the robot is disabled.
void Robot::RobotPeriodic() {
	//std::cout << "RobotPeriodic" << std::endl;
}

// This function is called once each time the robot enters Disabled mode.
// You can use it to reset any subsystem information you want to clear when
// the robot is disabled.
void Robot::DisabledInit() {
	std::cout << "DisabledInit" << std::endl;
}

// When the robot is in Disabled this method is called each time a new packet is received from the driver station.
void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

// Called each and every time autonomous is entered from another mode.
void Robot::AutonomousInit() {
	std::cout << "AutonomousInit" << std::endl;
	_autoMove->Initialize(250);
	_autoMove->Start();
	//autonomousCommand = (Command *) chooser->GetSelected();
	//autonomousCommand->Start();
}

// When the robot is in Autonomous mode this method is called each time a new packet is received from the driver station.
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Enc Left", CommandBase::driveTrain->EncGetLeft());
}

// Called each and every time teleop is entered from another mode.
void Robot::TeleopInit() {
	std::cout << "TeleopInit" << std::endl;

	CommandBase::oi->SetButton1PressedCommand(_shootBallCommand.get());

	CommandBase::driveTrain->GyroCalibrate();

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
	SmartDashboard::PutNumber("Gyro Angle", CommandBase::driveTrain->GetGyroAngle());
}

// Called each and every time test is entered from another mode.
void Robot::TestInit()
{
	std::cout << "TestInit" << std::endl;
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
