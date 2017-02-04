// ============================================================================
// FileName: PlaceCogCommand.h
//
// Description:
// Command for an 2017 FRC command based robot that attempts to place the cog
// onto the the flying machine. This command should be called once the bot is in
// close proximity to its destination (i.e. the camera(s) can quickly locate the
// guidance tape).
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


#ifndef PlaceCogCommand_H
#define PlaceCogCommand_H

#include "../../CommandBase.h"

class PlaceCogCommand : public CommandBase {
public:
	PlaceCogCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PlaceCogCommand_H
