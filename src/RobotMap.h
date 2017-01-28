#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// Drive Train
constexpr int DRIVETRAIN_LEFT_MOTOR = 0;
constexpr int DRIVETRAIN_RIGHT_MOTOR = 1;
constexpr double DRIVETRAIN_MAX_SPEED = 1.0;
constexpr double DRIVETRAIN_DEFAULT_MULTIPLIER = 0.5;
constexpr double DRIVETRAIN_ALT_MULTIPLIER = 0.5;

// Lifting
const int LIFTING_SPARK_LEFT_PIN = 3;
const int LIFTING_SPARK_RIGHT_PIN = 4;

// Shooter
const int SHOOTER_TALON_PIN = 2;
const bool SHOOTER_DEFAULT_DIRECTION = 1; // Inverted
const double SHOOTER_DEFAULT_SPEED = 0.95;

// Ball Pickup
const int SUCKER_TALON_PIN = 5;
const bool SUCKER_DEFAULT_DIRECTION = 1; // Inverted

// Driver Mapping
constexpr int DRIVER_JOY_NUM = 0;
constexpr int DRIVER_ALT_SPEED_BUTTON = 6;

// Assistant Mapping
constexpr int ASSISTANT_JOY_NUM = 1;

#endif  // ROBOTMAP_H
