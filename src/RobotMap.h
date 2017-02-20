#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

// Command Enumerator
enum class AutoCommand_t {
	AutoMoveCommand,
	AutoRotateCommand,
	AutoPlaceCogCommand
};

// Pixy
constexpr frc::I2C::Port PIXY_PORT = frc::I2C::Port::kOnboard;
constexpr uint8_t PIXY_ADDR = 0x54;

// Drive Train
constexpr int DRIVETRAIN_LEFT_MOTOR = 0;
constexpr int DRIVETRAIN_RIGHT_MOTOR = 1;
constexpr double DRIVETRAIN_MAX_SPEED = 1.0;
constexpr double DRIVETRAIN_DEFAULT_SPEED = 0.5;
constexpr double DRIVETRAIN_SHIFT_SPEED = 1.0;
constexpr int DRIVETRAIN_ENC_LEFT_A = 9;
constexpr int DRIVETRAIN_ENC_LEFT_B = 8;
constexpr int DRIVETRAIN_ENC_RIGHT_A = 7;
constexpr int DRIVETRAIN_ENC_RIGHT_B = 6;
constexpr int DRIVETRAIN_ANALOG_GYRO = 0;
constexpr int DRIVETRAIN_ULTRA_LEFT = 0;
constexpr int DRIVETRAIN_ULTRA_RIGHT = 1;

// Lifting
constexpr int LIFTER_SPARK_LEFT = 3;
constexpr int LIFTER_SPARK_RIGHT = 4;

// Shooter
const int SHOOTER_TALON_PIN = 2;
const bool SHOOTER_DEFAULT_DIRECTION = 1; // Inverted
const double SHOOTER_DEFAULT_SPEED = 0.95;

// Ball Pickup
const int PICKUP_TALON = 5;
const bool PICKUP_DEFAULT_DIRECTION = 1; // Inverted

// Driver Mapping
constexpr int DRIVER_JOY_NUM = 0;
constexpr int DRIVER_SPEED_AXIS = 3;
constexpr int DRIVER_THROTTLE_AXIS = 1;
constexpr int DRIVER_HEADING_AXIS = 4;

// Assistant Mapping
constexpr int ASSISTANT_JOY_NUM = 1;

#endif  // ROBOTMAP_H
