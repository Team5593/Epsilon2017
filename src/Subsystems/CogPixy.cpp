#include "CogPixy.h"
#include "../RobotMap.h"

CogPixy::CogPixy() : Subsystem("ExampleSubsystem"),
	_pixy()
{

}

void CogPixy::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

int CogPixy::GetX() {
	_pixy.GetBlocks(2);
	return (_pixy.blocks[0].x + _pixy.blocks[1].x) / 2;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
