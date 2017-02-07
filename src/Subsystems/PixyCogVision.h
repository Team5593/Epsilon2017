#ifndef PixyCogVision_H
#define PixyCogVision_H

#include <Commands/Subsystem.h>
#include "../Pixy/PixyI2C.h"
#include "SensorBase.h"

class PixyCogVision : public frc::Subsystem {
private:
	PixyI2C _pixy;
public:
	PixyCogVision();
	void InitDefaultCommand();
};

#endif  // PixyCogVision_H
