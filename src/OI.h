#ifndef OI_H
#define OI_H

#include <WPILib.h>
#include "RobotMap.h"

class OI {
public:
	OI(int joystickNumber);
	double GetThrottleAxis();
	double GetHeadingAxis();
	bool GetAltSpeedButton();
	void SetButton1PressedCommand(Command * command);

private:
	Joystick _driverJoy;
	JoystickButton _joystickButton1;
};

#endif  // OI_H
