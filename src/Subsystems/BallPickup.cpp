#include "BallPickup.h"
#include "../RobotMap.h"
#include "../Commands/BallPickupToggle.h"

BallPickup::BallPickup(int motorChannel) :
	frc::Subsystem("BallPickupSubsystem"),
	_pickupMotor(motorChannel)
{

}

void BallPickup::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new BallPickupToggle());
}

void BallPickup::Set(double speed) {
	_speed = speed;
	//std::cout << CommandBase::oi->RealGetDriverButton(6) << std::endl;
	if (CommandBase::oi->RealGetDriverButton(6)) {
		_pickupMotor.Set(-_speed);
	}
	else {
		_pickupMotor.Set(_speed);
	}

}

double BallPickup::Get() {
	return _speed;
}


