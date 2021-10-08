#include "comp/devices.hpp"

okapi::ChassisScales scales({3_in, 12_in}, imev5GreentTPR);

okapi::MotorGroup movement = MotorGroup();

okapi::MotorGroup inB = MotorGroup();

okapi::MotorGroup inF = MotorGroup();