#include "PixyCogVision.h"
#include "../RobotMap.h"

PixyCogVision::PixyCogVision() : Subsystem("ExampleSubsystem"), _pixy(uint8_t(0x54), frc::I2C::Port::kOnboard) {

}

void PixyCogVision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
