#pragma once
#include "main.h"

extern ChassisScales scales;
extern std::shared_ptr<okapi::ChassisModel> model;

extern std::shared_ptr<okapi::OdomChassisController> chassis;

extern okapi::Motor belt;

extern okapi::Controller controller;

enum trayStates {
	off,
	up,
	down
};

extern trayStates trayState;
