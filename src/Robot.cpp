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
	_lifterToggle = std::make_unique<Lift>();

	CommandBase::driveTrain->GyroCalibrate();

	CameraServer::GetInstance()->StartAutomaticCapture("Front Camera" , 0);
	CameraServer::GetInstance()->StartAutomaticCapture("Hopper Camera", 1);
	//CameraServer::GetInstance()->StartAutomaticCapture("Front Floor Facing", 3);
}


// Runs all of the time (including during disabled methods)
void Robot::RobotPeriodic() {
	//std::cout << "RobotPeriodic" << std::endl;

	if (CommandBase::oi->GetGamepadInput(GAMEPAD_BUTTON_R)) _autonomousSide = false;
	else if (CommandBase::oi->GetGamepadInput(GAMEPAD_BUTTON_B)) _autonomousSide = true;


	switch (_autonomousSide) {
	case false: _outputSide = GAMEPAD_OUTPUT_R; break;
	case true: _outputSide = GAMEPAD_OUTPUT_B; break;
	default: _outputSide = GAMEPAD_OUTPUT_R;
	}

	if (CommandBase::oi->GetGamepadInput(GAMEPAD_BUTTON_1)) _autonomousNum = 0;
	else if (CommandBase::oi->GetGamepadInput(GAMEPAD_BUTTON_2)) _autonomousNum = 1;
	else if (CommandBase::oi->GetGamepadInput(GAMEPAD_BUTTON_3)) _autonomousNum = 2;
	else if (CommandBase::oi->GetGamepadInput(GAMEPAD_BUTTON_4)) _autonomousNum = 3;


	switch (_autonomousNum) {
	case 0: _outputNum = GAMEPAD_OUTPUT_1; break;
	case 1: _outputNum = GAMEPAD_OUTPUT_2; break;
	case 2: _outputNum = GAMEPAD_OUTPUT_3; break;
	case 3: _outputNum = GAMEPAD_OUTPUT_4; break;
	default: _outputNum = GAMEPAD_OUTPUT_1;
	}

	// Clear Outputs
	CommandBase::oi->SetGamepadOutput(GAMEPAD_OUTPUT_1, false);
	CommandBase::oi->SetGamepadOutput(GAMEPAD_OUTPUT_2, false);
	CommandBase::oi->SetGamepadOutput(GAMEPAD_OUTPUT_3, false);
	CommandBase::oi->SetGamepadOutput(GAMEPAD_OUTPUT_4, false);
	CommandBase::oi->SetGamepadOutput(GAMEPAD_OUTPUT_R, false);
	CommandBase::oi->SetGamepadOutput(GAMEPAD_OUTPUT_B, false);
	// Set Output
	CommandBase::oi->SetGamepadOutput(_outputNum, true);
	CommandBase::oi->SetGamepadOutput(_outputSide, true);
}

// Run once when robot enters disabled mode
void Robot::DisabledInit() {
	std::cout << "DisabledInit" << std::endl;
	CommandBase::oi->SetRumbleLeft(0.0);
	CommandBase::oi->SetRumbleRight(0.0);
}

// Runs when robot is disabled
void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

// Run once when robot enters autonomous mode
void Robot::AutonomousInit() {
	std::cout << "AutonomousInit" << std::endl;
	CommandBase::driveTrain->EncResetAll();
	CommandBase::driveTrain->GyroReset();

	std::vector<std::pair<AutoCommand_t, double>> commandVec;
	if (_autonomousSide == false) {
		// RED Side
		switch(_autonomousNum) {
		case 0:
			// Left Driver Station
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, -64});
			commandVec.push_back({AutoCommand_t::AutoRotateCommand, 90});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 40});
			break;
		case 1:
			// Middle Driver Station
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, -64});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 40});
			break;
		case 2:
			// Right Driver Station
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, -64});
			commandVec.push_back({AutoCommand_t::AutoRotateCommand, -90});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 40});
			break;
		case 3:
			// Spare
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, -150});
			commandVec.push_back({AutoCommand_t::AutoRotateCommand, 180});
			break;
		}
	}
	else {
		// BLUE Side
		switch(_autonomousNum) {
		case 0:
			// Left Driver Station
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, -64});
			commandVec.push_back({AutoCommand_t::AutoRotateCommand, 90});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 40});
			break;
		case 1:
			// Middle Driver Station
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, -64});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 40});
			break;
		case 2:
			// Right Driver Station
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, -64});
			commandVec.push_back({AutoCommand_t::AutoRotateCommand, -90});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 40});
			break;
		case 3:
			// Spare
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, -150});
			commandVec.push_back({AutoCommand_t::AutoRotateCommand, 180});
			break;
		}
	}


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
	if (_deliverGearCommandGroup != NULL) {
		_deliverGearCommandGroup->Cancel();
	}
	CommandBase::oi->SetButtonHeldCommand( DRIVER_SHOOTER_BUTTON, (Command *)_shootBallCommand.get());
	CommandBase::oi->SetButtonHeldCommand( DRIVER_PICKUP_BUTTON, (Command *)_ballPickupToggle.get());
	CommandBase::oi->SetButtonHeldCommand( DRIVER_LIFTER_BUTTON, (Command *)_lifterToggle.get());

	//SmartDashboard::PutNumber("Gyro Angle", CommandBase::driveTrain->GetGyroAngle());
	//SmartDashboard::PutNumber("Shooter RPM", CommandBase::Shooter->GetEncoder());
	//SmartDashboard::PutNumber("Cog Pixy X", CommandBase::cogPixy->GetX());

}

// Runs when robot is in teleop mode
void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	LiveWindow::GetInstance()->Run();
	CommandBase::shooter->SetSetpoint(CommandBase::oi->GetShooterAxis());
}

// Run once when robot enters test mode
void Robot::TestInit() {
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
