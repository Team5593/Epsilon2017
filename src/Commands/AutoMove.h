#ifndef AutoMove_H
#define AutoMove_H

#include "../CommandBase.h"
#include "../Subsystems/DriveTrain.h"

class AutoMove : public CommandBase {
public:
	AutoMove(double relativeDistance, double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double _relativeDistance;
	double _speed = 0.5;
	bool _leftFinished = false;
	bool _rightFinished = false;
};

#endif  // AutoMove_H
