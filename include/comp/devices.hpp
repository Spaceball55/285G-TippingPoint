#pragma once
#include "main.h"

extern okapi::ControllerButton trayButton;

extern okapi::ControllerButton intakeButton;

extern okapi::ControllerButton clawButton;

extern okapi::ControllerButton fourBarButton;

extern ChassisScales scales;

extern std::shared_ptr<okapi::ChassisModel> model;

extern std::shared_ptr<okapi::OdomChassisController> chassis;

extern std::shared_ptr<okapi::OdomChassisController> autChassis;

extern okapi::Motor rTray;

extern okapi::Motor fbMotor;

extern okapi::Motor lTray;

extern okapi::Motor belt;

extern okapi::Motor claw;

extern okapi::Controller controller;

//extern okapi::Motor intake;

//extern TrayController trayController;

extern bool isBlue;

class TwoBar {
	public: 
	void lift();
};

class FourBar{
	public:
	void lift();
	void clawToggle();
};

extern bool td; //tells if tray is down

extern void trayUp();
extern void trayDown();

extern void clawUp();
extern void clawDown();

extern void trayMovement();

extern bool clawD;

