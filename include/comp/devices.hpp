#pragma once
#include "main.h"

extern ChassisScales scales;

extern std::shared_ptr<okapi::ChassisModel> model;

extern std::shared_ptr<okapi::OdomChassisController> chassis;

extern okapi::Motor belt;

extern okapi::Controller controller;

//extern TrayController trayController;

extern okapi::MotorGroup trayMove;

extern okapi::Motor rTray;
extern okapi::Motor lTray;

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

	void setState(TrayStates newState);
	void trayMovement();
};


extern bool trayUp;


extern void trayMovement();


class HammerController{
	public:
	enum Hammerstates {
		up,
		down,
		off
	};

	Hammerstates state = off;
	bool hammerSettled;

	void HammerTime();
};

extern bool HammerUp;