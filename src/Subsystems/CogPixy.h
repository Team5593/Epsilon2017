#ifndef CogPixy_H
#define CogPixy_H

#include <Commands/Subsystem.h>
#include <Pixy/PixyI2C.h>
#include <I2C.h>

class CogPixy : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	PixyI2C _pixy;
public:
	CogPixy();
	void InitDefaultCommand();
	int GetX();
	int GetWidth();
};

#endif  // CogPixy_H
