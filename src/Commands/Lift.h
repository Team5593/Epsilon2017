#ifndef Lift_H
#define Lift_H

#include "../CommandBase.h"
#include "../Subsystems/Lifter.h"

class Lift : public CommandBase {
public:
	Lift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool _isOn = false;
};

#endif  // Lift_H
