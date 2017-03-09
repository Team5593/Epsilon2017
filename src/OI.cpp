#include "OI.h"

OI::OI(int joystickNumber) :
	_driverJoy(joystickNumber),
	_gamepad(1),
	_joystickButton1(&_driverJoy, 1),
	_joystickButton2(&_driverJoy, 2),
	_joystickButton3(&_driverJoy, 3),
 	_joystickButton4(&_driverJoy, 4)
{ }

double OI::GetThrottleAxis() {
	return _driverJoy.GetRawAxis(DRIVER_THROTTLE_AXIS);
}

double OI::GetHeadingAxis() {
	return _driverJoy.GetRawAxis(DRIVER_HEADING_AXIS);
}

double OI::GetSpeedAxis() {
	double speed = _driverJoy.GetRawAxis(DRIVER_SPEED_AXIS);
	//std::cout << "Speed Axis Checked: " << speed << std::endl;
	return speed;
}

double OI::GetShooterAxis() {
	return (fabs(_gamepad.GetRawAxis(GAMEPAD_SHOOTER_AXIS)));
}

bool OI::GetDriverButton(int button) {
	return _driverJoy.GetRawButton(DRIVER_SHOOTER_BUTTON);
}

void OI::SetRumbleLeft(double value) {
	_driverJoy.SetRumble(_driverJoy.kLeftRumble, value);
}

void OI::SetRumbleRight(double value) {

	_driverJoy.SetRumble(_driverJoy.kRightRumble, value);
}

void OI::SetButtonPressedCommand(int buttonNum, Command * command) {
	// ToDo: It may work to create a new Button object every time but I can't see it being a good idea. For hardware resources it's likely to be always
	// better to create the object once and keep hold of the reference.
	// PLUS whenever you use "new" the object is created on the heap and YOU are responsible for calling delete to clean it up. Using "new" in this
	// sort of situation is a prime candidate for a memory leak. If the operator happened to hit a button a hundred times and each Button object reserved
	// a large chunk of memory it could easily cause a memory exhaustion exception and crash the robot program.
	//JoystickButton* button = new JoystickButton(&_driverJoy, buttonNum);
	//button->WhenPressed(command);
	switch(buttonNum) {
		case 1:
			_joystickButton1.WhenPressed(command);
			break;
		case 2:
			_joystickButton2.WhenPressed(command);
			break;
		case 3:
			_joystickButton3.WhenPressed(command);
			break;
		case 4:
			_joystickButton4.WhenPressed(command);
			break;
		default:
			std::cout << "Button number " << buttonNum << " has not been configured in OI.cpp." << std::endl;

	}
}

void OI::SetButtonHeldCommand(int buttonNum, Command * command) {
	//JoystickButton* button = new JoystickButton(&_driverJoy, buttonNum);
	//button->WhileHeld(command);
	switch(buttonNum) {
		case 1:
			_joystickButton1.WhileHeld(command);
			break;
		case 2:
			_joystickButton2.WhileHeld(command);
			break;
		case 3:
			_joystickButton3.WhileHeld(command);
			break;
		case 4:
			_joystickButton4.WhileHeld(command);
			break;
		default:
			std::cout << "Button number " << buttonNum << " has not been configured in OI.cpp." << std::endl;

	}
}

void OI::SetButtonToggleWhenPressedCommand(int buttonNum, Command * command) {
	switch(buttonNum) {
		case 1:
			_joystickButton1.ToggleWhenPressed(command);
			break;
		case 2:
			_joystickButton2.ToggleWhenPressed(command);
			break;
		case 3:
			_joystickButton3.ToggleWhenPressed(command);
			break;
		case 4:
			_joystickButton4.ToggleWhenPressed(command);
			break;
		default:
			std::cout << "Button number " << buttonNum << " has not been configured in OI.cpp." << std::endl;

	}
}

void OI::SetGamepadOutput(int output, bool value) {
	_gamepad.SetOutput(output, value);
}

bool OI::GetGamepadInput(int input) {
	return _gamepad.GetRawButton(input);
}
