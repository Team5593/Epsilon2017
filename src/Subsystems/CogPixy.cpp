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
	_pixy.GetBlocks();
	// Only select blocks with signature 1
	int n = 0;
	int avg = 0;
	for (int i = 0; i < _pixy.blockCount; i++) {
		if (_pixy.blocks[i].signature == 1) {
			n++;
			avg += _pixy.blocks[i].x;
		}
	}
	avg = avg / n;
	return avg;
}

int CogPixy::GetWidth() {
	_pixy.GetBlocks(2);
	return (_pixy.blocks[0].width + _pixy.blocks[1].width);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
