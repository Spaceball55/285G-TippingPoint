#include "main.h"
#include "comp/devices.hpp"

bool tankDrive = false;

okapi::ControllerButton trayButton = okapi::ControllerDigital::L1;

TrayController tray;

void on_center_button() {}

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

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
