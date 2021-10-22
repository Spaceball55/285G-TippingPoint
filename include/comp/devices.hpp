#pragma once;
#include "main.h"

extern ChassissScales scales;
extern std::shared_ptr<okapi::ChassisModel> model;

extern std::shared_ptr<okapi::ChassisController> chassis;

extern okapi::Motor belt;

enum trayStates {
	off,
	up,
	down
};

extern trayStates trayState;
