#ifndef BallPickupToggle_H
#define BallPickupToggle_H

#include "../CommandBase.h"
#include "../Subsystems/BallPickup.h"

class BallPickupToggle : public CommandBase {
public:
	BallPickupToggle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // BallPickupToggle_H
