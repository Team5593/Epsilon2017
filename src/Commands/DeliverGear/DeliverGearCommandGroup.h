// ============================================================================
// FileName: DeliverGearCommandGroup.h
//
// Description:
// Command group for an 2017 FRC command based robot that aims to deliver the
// gear cog to from the robot's starting position to the flying machine.
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

#ifndef DeliverGearCommandGroup_H
#define DeliverGearCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/AutoRotate.h"
#include "Commands/AutoMove.h"
#include "PlaceCogCommand.h"

#define ROTATE_COMMAND_EXPIRY_SECONDS 5.0		// If the auto rotate takes longer than this assume something has gone wrong and terminate the command.
#define DRIVE_FORWARDS_COMMAND_EXPIRY_SECONDS 5.0		// If the drive set distance takes longer thanthis assume something has gone wrong and terminate the command.

class DeliverGearCommandGroup : public CommandGroup {
public:
	DeliverGearCommandGroup(double rotationAngle, double firstForwardDistance);
private:
	AutoRotate * _autoRotateCommand { nullptr };
	AutoMove * _autoMoveCommand { nullptr};
	PlaceCogCommand * _placeCogCommand { nullptr};
};

#endif  // DeliverGearCommandGroup_H
