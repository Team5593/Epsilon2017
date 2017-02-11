#ifndef CogLoaderPixy_H
#define CogLoaderPixy_H

#include <Commands/Subsystem.h>
#include <Pixy/PixyI2C.h>

class CogLoaderPixy : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	PixyI2C _pixy;
public:
	CogLoaderPixy();
	void InitDefaultCommand();
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
};

#endif  // CogLoaderPixy_H
