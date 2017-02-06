// ============================================================================
// FileName: DriveSetDistanceCommand.h
//
// Description:
// Command for an 2017 FRC command based robot that attempts to drive forwards
// a specific set distance.
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

#ifndef DriveSetDistanceCommand_H
#define DriveSetDistanceCommand_H

#include "../../CommandBase.h"

class DriveSetDistanceCommand : public CommandBase {
public:
	DriveSetDistanceCommand();
	void Initialize(double distanceCentimeters);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveSetDistanceCommand_H
