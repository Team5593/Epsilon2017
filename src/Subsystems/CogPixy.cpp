#include "CogPixy.h"
#include "../RobotMap.h"

CogPixy::CogPixy() : Subsystem("CogPixySubsystem"),
	_pixy()
{

}

void CogPixy::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

int CogPixy::GetX() {
	_pixy.GetBlocks(2);
	return (_pixy.blocks[0].x + _pixy.blocks[0].width/2) + ((_pixy.blocks[0].x + _pixy.blocks[0].width/2) - (_pixy.blocks[1].x + _pixy.blocks[1].width/2)) / 2;
}

int CogPixy::GetWidth() {
	_pixy.GetBlocks(2);
	return (_pixy.blocks[0].width + _pixy.blocks[1].width);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
