#include "OI.h"

OI::OI() {

}

double OI::GetThrottleAxis(int JoyNum) {
	switch(JoyNum) {
	case DRIVER_JOY_NUM: return driverJoy->GetRawAxis(DRIVER_THROTTLE_AXIS); break;
	default: return 0.0; break;
	}
}

double OI::GetHeadingAxis(int JoyNum) {
	switch(JoyNum) {
	case DRIVER_JOY_NUM: return driverJoy->GetRawAxis(DRIVER_HEADING_AXIS); break;
	default: return 0.0; break;
	}
}
