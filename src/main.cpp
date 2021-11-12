#include "main.h"
#include "comp/devices.hpp"

bool tankDrive = false;

bool isBlue = true;

okapi::ControllerButton trayButton = okapi::ControllerDigital::L1;

okapi::ControllerButton armButton = okapi::ControllerDigital::L2;

TrayController tray;

void on_center_button() {}

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	std::shared_ptr<OdomChassisController> chassis = 
	ChassisControllerBuilder().withMotors({-10,-2}, {11, 20}).withDimensions(okapi::AbstractMotor::gearset::green, scales).withOdometry(scales, okapi::StateMode::CARTESIAN, 0_mm, 0_deg).buildOdometry();

	std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());


	/*
	plan:

	start with tray down
	pick up the mogo
	move it
	drop preload onto goals (before/after the previous step)
	pick up more rings and drop into mogo
	basic auton finished!
	*/
}

void opcontrol() {

	while(1){
		
		if(tankDrive==true){
			model->tank(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightY));
			//tank drive using left and right to move
			
		}
		else{
			model->arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
			//arcade control, in case we need it
			
		}

		if(trayButton.changedToPressed()){
			if(trayUp){
				tray.setState(TrayController::TrayStates::down);
			}
			else{
				tray.setState(TrayController::TrayStates::up);
			}
		}
	}
}
