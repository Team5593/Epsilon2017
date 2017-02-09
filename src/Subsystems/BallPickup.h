#ifndef BallPickup_H
#define BallPickup_H

#include <Commands/Subsystem.h>
#include <TalonSRX.h>

class BallPickup : public frc::Subsystem {
private:
	frc::TalonSRX _pickupMotor;
	double _speed = 0;
public:
	BallPickup(int pickupChannel);
	void InitDefaultCommand();
	void Set(double speed);
	double Get();
};

#endif  // BallPickup_H
