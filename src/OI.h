#ifndef OI_H
#define OI_H

#include <WPILib.h>

class OI {
public:
	Joystick driverJoy = new Joystick(DRIVER_JOY_NUM);
	OI();
	double GetThrottleAxis(int JoyNum);
	double GetHeadingAxis(int JoyNum);
};

#endif  // OI_H
