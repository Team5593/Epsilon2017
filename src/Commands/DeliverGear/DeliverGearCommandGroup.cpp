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

// rotationAngle: The angle in degrees for the first rotation of the robot.
// firstForwardDistance: The distance for the first drive forwards in centimeters.
DeliverGearCommandGroup::DeliverGearCommandGroup(double rotationAngle, double firstForwardDistance) {
	_autoRotateCommand = new AutoRotate();
	_autoRotateCommand->Initialize(rotationAngle);

	_autoMoveCommand = new AutoMove();
	_autoMoveCommand->Initialize(firstForwardDistance);

	// ToDo: Add additional rotate and drive commands to get the bot in approximate position for the vision processing to take over.

	_placeCogCommand = new PlaceCogCommand();

	AddSequential(_autoRotateCommand, ROTATE_COMMAND_EXPIRY_SECONDS);
	AddSequential(_autoMoveCommand, DRIVE_FORWARDS_COMMAND_EXPIRY_SECONDS);
	AddSequential(_placeCogCommand);
}
