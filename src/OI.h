#ifndef OI_H
#define OI_H

#include <WPILib.h>
#include "RobotMap.h"

class OI {
public:
	OI(int joystickNumber);
	double GetThrottleAxis();
	double GetHeadingAxis();
	bool GetShiftButton();
	void SetRumbleLeft(double value);
	void SetRumbleRight(double value);
	void SetButtonPressedCommand(int buttonNum, Command * command);
	void SetButtonHeldCommand(int buttonNum, Command * command);
	void SetButtonToggleWhenPressedCommand(int buttonNum, Command * command);

private:
	Joystick _driverJoy;
	JoystickButton _joystickButton1;
	JoystickButton _joystickButton2;
	JoystickButton _joystickButton3;
	JoystickButton _joystickButton4;
};

#endif  // OI_H
