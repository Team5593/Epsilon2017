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
	_placeCog = std::make_unique<PlaceCog>();

	CommandBase::driveTrain->GyroCalibrate();

	//ToDo CameraServer::GetInstance()->StartAutomaticCapture("Front Camera" , 0);
	//CameraServer::GetInstance()->StartAutomaticCapture("Ball Camera", 1);
	//CameraServer::GetInstance()->StartAutomaticCapture("Front Floor Facing", 3);
}

// Runs all of the time (including during disabled methods)
void Robot::RobotPeriodic() {
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

	if (CommandBase::oi->GetGamepadInput(GAMEPAD_BUTTON_R)) _autonomousSide = true;
	else if (CommandBase::oi->GetGamepadInput(GAMEPAD_BUTTON_B)) _autonomousSide = false;
	switch (_autonomousSide) {
		case false: _outputSide = GAMEPAD_OUTPUT_B; break;
		case true: _outputSide = GAMEPAD_OUTPUT_R; break;
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

// Run once when robot enters autonomous mode
void Robot::AutonomousInit() {
	std::cout << "AutonomousInit 1.2" << std::endl;

	// Reset Sensors
	CommandBase::driveTrain->EncResetAll();
	CommandBase::driveTrain->GyroReset();

	// Create vector
	std::vector<std::pair<AutoCommand_t, double>> commandVec;

	// Set autonomous vector
	if (_autonomousSide == false) {
		// RED Side
		switch(_autonomousNum) {
		case 2://0:
			std::cout << "RED LEFT" << std::endl;
			// Left Driver Station (closest to judge's station, forward & right)
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, 108});
			commandVec.push_back({AutoCommand_t::AutoRotateCommand, 60});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 80});
			break;
		case 3: //1:
			std::cout << "RED MIDDLE" << std::endl;
			// Middle Driver Station
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, 108});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 100});
			break;
		case 1: //2:
			std::cout << "RED RIGHT" << std::endl;
			// Right Driver Station (furtherest from judge's station, forward & left).
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, 120});
			commandVec.push_back({AutoCommand_t::AutoRotateCommand, -60});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 80});
			break;
		case 0://3:
			std::cout << "RED SPARE" << std::endl;
			// Spare
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, 150});
			//commandVec.push_back({AutoCommand_t::AutoRotateCommand, 180});
			break;
		}
	}
	else {
		// BLUE Side
		switch(_autonomousNum) {
		case 2: //0:
			std::cout << "BLUE LEFT" << std::endl;
			// Left Driver Station (furtherest from judge's station, forward & right).
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, 120});
			commandVec.push_back({AutoCommand_t::AutoRotateCommand, 60});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 80});
			break;
		case 3: //1:
			std::cout << "BLUE MIDDLE" << std::endl;
			// Middle Driver Station
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, 108});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 100});
			break;
		case 1: //2:
			std::cout << "BLUE RIGHT" << std::endl;
			// Right Driver Station (closest to judge's station, forward & left).
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, 108});
			commandVec.push_back({AutoCommand_t::AutoRotateCommand, -60});
			commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 100});
			break;
		case 0: //3:
			std::cout << "BLUE SPARE" << std::endl;
			// Spare
			commandVec.push_back({AutoCommand_t::AutoMoveCommand, 150});
			//commandVec.push_back({AutoCommand_t::AutoPlaceCogCommand, 80});
			break;
		}
	}

	// Init and run command group
	_deliverGearCommandGroup.reset(new DeliverGearCommandGroup());
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
	if (_deliverGearCommandGroup != nullptr) {
		_deliverGearCommandGroup->Cancel();
	}

	if (_placeCog != nullptr) {
		_placeCog->Cancel();
	}

	// Attach buttons to commands
	CommandBase::oi->SetButtonHeldCommand( DRIVER_SHOOTER_BUTTON, (Command *)_shootBallCommand.get());
	CommandBase::oi->SetButtonHeldCommand( DRIVER_PICKUP_BUTTON, (Command *)_ballPickupToggle.get());
	CommandBase::oi->SetButtonHeldCommand( DRIVER_LIFTER_BUTTON, (Command *)_lifterToggle.get());
	CommandBase::oi->SetButtonHeldCommand( DRIVER_COGPLACE_BUTTON, (Command *)_placeCog.get());
}

// Runs when robot is in teleop mode
void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	LiveWindow::GetInstance()->Run();

	// Set shooter value
	CommandBase::shooter->SetSetpoint(CommandBase::oi->GetShooterAxis());

	// Smart dashboard
	SmartDashboard::PutNumber("Shooter RPM", CommandBase::shooter->GetEncoder());
	SmartDashboard::PutNumber("Shooter Setpoint", CommandBase::shooter->GetSetpoint());
}

// Run once when robot enters test mode
void Robot::TestInit() {
	std::cout << "TestInit AM 2" << std::endl;
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
