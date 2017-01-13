#ifndef AutonomousTestCommand_H
#define AutonomousTestCommand_H

#include "../CommandBase.h"

class AutonomousTestCommand : public CommandBase {
public:
	AutonomousTestCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutonomousTestCommand_H
