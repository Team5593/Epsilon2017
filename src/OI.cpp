#include "OI.h"

OI::OI(int joystickNumber) :
	_driverJoy(joystickNumber)
{ }

double OI::GetThrottleAxis() {
	return _driverJoy.GetRawAxis(DRIVER_THROTTLE_AXIS);
}

double OI::GetHeadingAxis() {
	return _driverJoy.GetRawAxis(DRIVER_HEADING_AXIS);
}

bool OI::GetShiftButton() {
	bool state = _driverJoy.GetRawButton(DRIVER_SHIFT_BUTTON);
	//std::cout << "Shift Button Checked: " << state << std::endl;
	return state;
}

void OI::SetButtonPressedCommand(int buttonNum, Command * command) {
	JoystickButton* button = new JoystickButton(&_driverJoy, buttonNum);
	button->WhenPressed(command);
}

void OI::SetButtonHeldCommand(int buttonNum, Command * command) {
	JoystickButton* button = new JoystickButton(&_driverJoy, buttonNum);
	button->WhileHeld(command);
}
