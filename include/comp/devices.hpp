#pragma once
#include "main.h"

extern ChassisScales scales;
extern std::shared_ptr<okapi::ChassisModel> model;

extern std::shared_ptr<okapi::OdomChassisController> chassis;

extern okapi::Motor belt;

enum trayStates {
	off,
	up,
	down
};

extern trayStates trayState;
