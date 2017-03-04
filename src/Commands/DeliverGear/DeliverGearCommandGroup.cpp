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
	//driveTrain->GyroReset();
}

void DeliverGearCommandGroup::Initialize(std::vector<std::pair<AutoCommand_t, double>> v) {
	std::cout << "DG CG Init" << std::endl;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		auto item = (*iter);
		switch(item.first) {
			case AutoCommand_t::AutoMoveCommand:
			{
				std::cout << "AutoMove" << item.second << std::endl;
				auto autoMoveCommand = new AutoMove();
				autoMoveCommand->Initialize(item.second);
				AddSequential(autoMoveCommand, EXPIRY_SECONDS);
				break;
			}
			case AutoCommand_t::AutoRotateCommand:
			{
				std::cout << "AutoRotate" << item.second << std::endl;
				auto autoRotateCommand = new AutoRotate();
				autoRotateCommand->Initialize(item.second);
				AddSequential(autoRotateCommand, EXPIRY_SECONDS);
				break;
			}
			case AutoCommand_t::AutoPlaceCogCommand:
			{
				std::cout << "AutoRotate" << item.second << std::endl;
				auto autoPlaceCogCommand = new PlaceCog();
				autoPlaceCogCommand->Initialize(item.second);
				AddSequential(autoPlaceCogCommand, EXPIRY_SECONDS);
				break;
			}
		}
	}
}
