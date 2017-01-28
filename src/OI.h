#ifndef OI_H
#define OI_H

#include <WPILib.h>

constexpr int DRIVER_THROTTLE_AXIS = 1;
constexpr int DRIVER_HEADING_AXIS = 4;

class OI {
public:
	OI(int joystickNumber);
	double GetThrottleAxis();
	double GetHeadingAxis();
	void SetButton1PressedCommand(Command * command);

private:
	Joystick _driverJoy;
	JoystickButton _joystickButton1;
};

#endif  // OI_H
