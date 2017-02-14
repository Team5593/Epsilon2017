#include <Subsystems/Lifter.h>
#include "../RobotMap.h"

Lifter::Lifter(int leftMotor, int rightMotor) : Subsystem("ExampleSubsystem"),
	_liftLeft(leftMotor),
	_liftRight(rightMotor)
	{

	}

void Lifter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lifter::Set(double speed) {
	_liftLeft.Set(speed);
	_liftRight.Set(speed);
}
