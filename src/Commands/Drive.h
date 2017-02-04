#ifndef Drive_H
#define Drive_H

#include "../CommandBase.h"
#include "../Subsystems/DriveTrain.h"

class Drive : public CommandBase {
private:
	bool _altSpeedState = false;
	bool _altButtonLastState = false;
public:
	Drive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Drive_H
