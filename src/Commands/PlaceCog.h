#ifndef PlaceCog_H
#define PlaceCog_H

#include "../CommandBase.h"
#include "../Subsystems/CogPixy.h"

class PlaceCog : public CommandBase {
public:
	PlaceCog();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool ultraLeftFinished;
	bool ultraRightFinished
};

#endif  // PlaceCog_H
