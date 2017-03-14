#ifndef PlaceCog_H
#define PlaceCog_H

#include "../CommandBase.h"
#include "../Subsystems/CogPixy.h"

class PlaceCog : public CommandBase {
public:
	PlaceCog();
	void Initialize(double value);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double _finishWidthValue = 100;
};

#endif  // PlaceCog_H
