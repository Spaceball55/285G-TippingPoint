#include "main.h"
#include "comp/devices.hpp"

std::shared_ptr<okapi::AsyncMotionProfileController> autoChassis =
  okapi::AsyncMotionProfileControllerBuilder()
    .withLimits({
      2.0, // Maximum linear velocity of the Chassis in m/s
      8.0, // Maximum linear acceleration of the Chassis in m/s/s
      15.0 // Maximum linear jerk of the Chassis in m/s/s/s
    })
    .withOutput(chassis)
    .buildMotionProfileController();


bool tankDrive = false;

bool isBlue = true;

TwoBar tb;
FourBar fb;

//hammerWork.updateState(HammerController::HammerStates::up);

void on_center_button() {}

void initialize() {

	//hammerWork.updateState(HammerController::HammerStates::up);
	
	pros::lcd::initialize();

	pros::lcd::set_text(1, "Hammerstate set to up!");
}

void disabled() {}

void competition_initialize() {

	autoChassis->generatePath({
	{0_ft, 0_ft, 0_deg}, {3_ft, 0_ft, 0_deg}}, "A");

}

void autonomous() {
	
/*
	std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());


	//red 

	autChassis->setDefaultStateMode(okapi::StateMode::CARTESIAN);
	


	//easy one idk
	autChassis->setState({0_in, 120_in, 0_deg});
	belt.moveVelocity(500);
	pros::delay(2000);
	belt.moveVelocity(0);
	autChassis->driveToPoint({0_in, 125_in});
	pros::delay(100);
	autChassis->turnToAngle(90_deg);
	autChassis->driveToPoint({60_in, 125_in});
	
	// for when we do skills:

	autChassis->moveDistance(12_in);
	*/
/*
	while(1){
	autChassis->turnAngle(-90_deg);
	autChassis->moveDistance(48_in);
	autChassis->moveDistance(-48_in);
	autChassis->turnAngle(90_deg);
	}
	autChassis->turnAngle(-90_deg);
	autChassis->moveDistance(48_in);
	autChassis->moveDistance(-48_in);
	autChassis->turnAngle(90_deg);

	autChassis->turnAngle(-90_deg);
	autChassis->moveDistance(48_in);
	autChassis->moveDistance(-48_in);
	autChassis->turnAngle(90_deg);
*/
/*
	autChassis->driveToPoint({60_in, 108_in});
	pros::delay(100);
	autChassis->driveToPoint({96_in, 108_in});
	pros::delay(100);
*/

	//autChassis->driveToPoint(108_in, );
	
	//intake.moveVelocity(200);

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

		tb.lift();
		fb.clawToggle();
		fb.lift();
		
		if(intakeButton.isPressed()){
			belt.moveVelocity(550);
		}
		else{
			belt.moveVelocity(0);
		}
	}
}
