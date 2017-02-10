#ifndef AutoRotate_H
#define AutoRotate_H

#include "../CommandBase.h"
#include "../Subsystems/DriveTrain.h"

class AutoRotate : public CommandBase {
public:
	AutoRotate();
	void Initialize(double angle);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double _relativeAngle = 0;
};

#endif  // AutoRotate_H
