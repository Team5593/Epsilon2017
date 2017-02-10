// ============================================================================
// FileName: DeliverGearCommandGroup.cpp
//
// Description:
// See header.
//
// Author(s):
// Team 5593
//
// History:
// 04 Feb 2017	Team 5593	Created.
//
// License:
// Public Domain
// ============================================================================

#include <Commands/DeliverGear/DeliverGearCommandGroup.h>

DeliverGearCommandGroup::DeliverGearCommandGroup() {	
	// ToDo: Add additional rotate and drive commands to get the bot in approximate position for the vision processing to take over.
	//AddSequential(_autoMoveCommand, DRIVE_FORWARDS_COMMAND_EXPIRY_SECONDS);
	//AddSequential(_autoRotateCommand, ROTATE_COMMAND_EXPIRY_SECONDS);
	//AddSequential(_autoMoveCommand, DRIVE_FORWARDS_COMMAND_EXPIRY_SECONDS);
	//AddSequential(_autoRotateCommand, ROTATE_COMMAND_EXPIRY_SECONDS);
}

void DeliverGearCommandGroup::Initialize(std::vector<std::pair<AutoCommand_t, double>> v) {
	std::cout << "DG CG Init" << std::endl;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		auto item = (*iter);
		switch(item.first) {
			case AutoCommand_t::AutoMoveEnum:
			{
				std::cout << "AutoMove" << item.second << std::endl;
				auto autoMoveCommand = new AutoMove();
				autoMoveCommand->Initialize(item.second);
				AddSequential(autoMoveCommand, DRIVE_FORWARDS_COMMAND_EXPIRY_SECONDS);
				break;
			}
			case AutoCommand_t::AutoRotateEnum:
			{
				std::cout << "AutoRotate" << item.second << std::endl;
				auto autoRotateCommand = new AutoRotate();
				autoRotateCommand->Initialize(item.second);
				AddSequential(autoRotateCommand, ROTATE_COMMAND_EXPIRY_SECONDS);
				break;
			}
		}
	}
}
