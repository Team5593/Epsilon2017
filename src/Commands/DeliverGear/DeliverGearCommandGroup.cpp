// ============================================================================
// FileName: DeliverGearCommandGroup.cpp
//
// Description:
// See header.
//
// Author(s):
// Team 5593
//
// History:
// 04 Feb 2017	Team 5593	Created.
//
// License:
// Public Domain
// ============================================================================

#include <Commands/DeliverGear/DeliverGearCommandGroup.h>

DeliverGearCommandGroup::DeliverGearCommandGroup() {
	_autoRotateCommand = new AutoRotate();
	_autoMoveCommand = new AutoMove();
	// ToDo: Add additional rotate and drive commands to get the bot in approximate position for the vision processing to take over.

	_autoMoveCommand->AddToQueue(50);
	AddSequential(_autoMoveCommand, DRIVE_FORWARDS_COMMAND_EXPIRY_SECONDS);
	AddSequential(_autoRotateCommand, ROTATE_COMMAND_EXPIRY_SECONDS);
	_autoMoveCommand->AddToQueue(50);
	AddSequential(_autoMoveCommand, DRIVE_FORWARDS_COMMAND_EXPIRY_SECONDS);
	AddSequential(_autoRotateCommand, ROTATE_COMMAND_EXPIRY_SECONDS);
}
