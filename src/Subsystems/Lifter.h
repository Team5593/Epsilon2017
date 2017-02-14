#ifndef Lifter_H
#define Lifter_H

#include <Commands/Subsystem.h>
#include <Talon.h>

class Lifter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	frc::Talon _liftLeft;
	frc::Talon _liftRight;
public:
	Lifter(int leftMotor, int rightMotor);
	void InitDefaultCommand();
	void Set(double speed);
};

#endif  // Lifting_H
