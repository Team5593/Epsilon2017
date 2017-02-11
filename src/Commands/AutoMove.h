#ifndef AutoMove_H
#define AutoMove_H

#include "../CommandBase.h"
#include "../Subsystems/DriveTrain.h"

class AutoMove : public CommandBase {
public:
	AutoMove();
	void Initialize(double distance);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double _relativeDistance;
	double _speed = 0.5;
	bool _leftFinished = false;
	bool _rightFinished = false;
	bool _firstExecute = true;
};

#endif  // AutoMove_H
