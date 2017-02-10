#ifndef AutoMove_H
#define AutoMove_H

#include "../CommandBase.h"
#include "../Subsystems/DriveTrain.h"

class AutoMove : public CommandBase {
public:
	AutoMove();
	void AddToQueue(double relativeDistance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::vector<double> distanceArray;
	int arrayPos = 0;
	double _relativeDistance;
	double _speed = 0.5;
	bool _leftFinished = false;
	bool _rightFinished = false;
};

#endif  // AutoMove_H
