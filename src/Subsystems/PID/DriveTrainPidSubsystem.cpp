// ============================================================================
// FileName: DriveTrainPidSubsystem.cpp
//
// Description:
// See header.
//
// Author(s):
// Team 5593
//
// History:
// 07 Feb 2017	Team 5593	Created.
//
// License:
// Public Domain
// ============================================================================

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/PID/DriveTrainPidSubsystem.h>

#include "RobotMap.h"

DriveTrainPidSubsystem::DriveTrainPidSubsystem() : PIDSubsystem("DriveTrainPidSubSystem", 1.0, 0.0, 0.0) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double DriveTrainPidSubsystem::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
}

void DriveTrainPidSubsystem::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void DriveTrainPidSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Drive());
}
