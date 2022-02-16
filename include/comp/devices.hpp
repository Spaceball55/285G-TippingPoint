#pragma once
#include "main.h"

extern ChassisScales scales;

extern std::shared_ptr<okapi::ChassisModel> model;

extern std::shared_ptr<okapi::OdomChassisController> chassis;

extern std::shared_ptr<okapi::OdomChassisController> autChassis;


extern okapi::Motor belt;

extern okapi::Controller controller;

//extern okapi::Motor intake;

//extern TrayController trayController;

extern okapi::MotorGroup trayMove;

extern okapi::Motor rTray;
extern okapi::Motor lTray;

extern okapi::Motor hammer;

extern bool isBlue;

class TrayController{
public:
	
	enum TrayStates {
		off,
		up,
		down
	};

	//TrayStates state;
	TrayStates state = off;
	TrayStates getState();

	bool settled;
	double error;
	std::shared_ptr<okapi::Motor> trayMotor; //plan is to track just the right motor

	//TrayController(std::shared_ptr<okapi::Motor> imotor); 

	void raise(double level);

	void setNewState(TrayStates newState);
	void trayMovement();
};


extern bool trayUp;


extern void trayMovement();


class HammerController{
	public:
	enum HammerStates {
		off,
		up,
		down
	};

	HammerStates hState = off;
	bool hammerSettled;

	void updateState(HammerStates newHState);
	void hammerTime();
};

extern bool hammerUp;