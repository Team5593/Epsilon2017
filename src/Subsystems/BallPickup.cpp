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
	_pickupMotor.Set(_speed);
}

double BallPickup::Get() {
	return _speed;
}


