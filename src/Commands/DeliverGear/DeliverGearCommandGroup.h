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

#include <RobotMap.h>
#include <vector>
#include <utility>
#include <Commands/CommandGroup.h>
#include "Commands/AutoRotate.h"
#include "Commands/AutoMove.h"
#include "Commands/PlaceCog.h"

const double EXPIRY_SECONDS = 5.0;		// If the auto rotate takes longer than this assume something has gone wrong and terminate the command.

class DeliverGearCommandGroup : public CommandGroup {
public:
	DeliverGearCommandGroup();
	void Initialize(std::vector<std::pair<AutoCommand_t, double>> v);
private:
};

#endif  // DeliverGearCommandGroup_H
