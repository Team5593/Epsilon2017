// ============================================================================
// FileName: DriveTrainPidSubsystem.cpp
//
// Description:
// Placeholder for a PID (Proportional, Integral, and Differential) Subsystem class
// that could be used to drive the robot.
// The guess is this would be used for autonomous drive commands rather than for Teleop.
// Perhaps the AutoMove command could benefit from a PID subsystem?
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

#ifndef DriveTrainPidSubsystem_H
#define DriveTrainPidSubsystem_H

#include <Commands/PIDSubsystem.h>
#include "Commands/Drive.h"

class DriveTrainPidSubsystem : public PIDSubsystem {
public:
	DriveTrainPidSubsystem();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif  // DriveTrainPidSubsystem_H
