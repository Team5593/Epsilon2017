#ifndef AutoMove_H
#define AutoMove_H

#include "../CommandBase.h"
#include "../Subsystems/DriveTrain.h"

class AutoMove : public CommandBase {
public:
	AutoMove();
	void Initialize(double relativeDistance, double speed);
	void Initialize(double relativeDistance);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double _relativeDistance;
	double _speed = 0.5;
	bool _leftFinished;
	bool _rightFinished;
};

#endif  // AutoMove_H
