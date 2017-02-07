#ifndef AutoMove_H
#define AutoMove_H

#include "../CommandBase.h"
#include "../Subsystems/DriveTrain.h"

class AutoMove : public CommandBase {
public:
	AutoMove();
	void Initialize(double relativeDistance);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double _relativeDistance;
	bool _leftFinished;
	bool _rightFinished;
};

#endif  // AutoMove_H
