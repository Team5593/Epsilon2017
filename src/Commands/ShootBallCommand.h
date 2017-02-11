// ============================================================================
// FileName: ShooterBallCommand.h
//
// Description:
// Command for a 2017 FRC command based robot that can shoot single or multiple
// balls into the boiler.
//
// Author(s):
// Team 5593
//
// History:
// 28 Jan 2017	Team 5593	Created.
//
// License:
// Public Domain
// ============================================================================

#ifndef ShootBallCommand_H
#define ShootBallCommand_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterSubsystem.h"

class ShootBallCommand : public CommandBase {
public:
	ShootBallCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool _isOn = false;
};

#endif  // ShootBallCommand_H
