#include "CogLoaderPixy.h"
#include "../RobotMap.h"

CogLoaderPixy::CogLoaderPixy() : Subsystem("ExampleSubsystem"),
	_pixy(0x54)
{

}

void CogLoaderPixy::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

int CogLoaderPixy::GetX() {
	_pixy.GetBlocks(2);
	return abs(_pixy.blocks[0].x - _pixy.blocks[1].x);
}

int CogLoaderPixy::GetY() {
	_pixy.GetBlocks(2);
	return abs(_pixy.blocks[0].y - _pixy.blocks[1].y);
}

int CogLoaderPixy::GetWidth() { // Note: this is an average of the width of a both block, not the height of the entire vision helper
	_pixy.GetBlocks(2);
	return abs((_pixy.blocks[0].width + _pixy.blocks[1].width) / 2);
}

int CogLoaderPixy::GetHeight() { // Note: this is an average of the height of both blocks, not the height of the entire vision helper
	_pixy.GetBlocks(2);
	return abs((_pixy.blocks[0].height + _pixy.blocks[1].height) / 2);
}

