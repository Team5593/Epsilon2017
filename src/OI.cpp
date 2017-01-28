#include "OI.h"

OI::OI(int joystickNumber) :
	_driverJoy(joystickNumber),
	_joystickButton1(&_driverJoy, 1)
{ }

double OI::GetThrottleAxis() {
	return _driverJoy.GetRawAxis(DRIVER_THROTTLE_AXIS);
}

double OI::GetHeadingAxis() {
	return _driverJoy.GetRawAxis(DRIVER_HEADING_AXIS);
}

bool OI::GetAltSpeedButton() {
	return _driverJoy.GetRawButton(DRIVER_ALT_SPEED_BUTTON);
}

void OI::SetButton1PressedCommand(Command * command) {
	_joystickButton1.WhenPressed(command);
}
