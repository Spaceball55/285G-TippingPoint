#include "comp/devices.hpp"

okapi::ChassisScales scales({3_in, 12_in}, imev5GreentTPR);

okapi::MotorGroup movement = MotorGroup({10,2,-11,-20});

//okapi::MotorGroup inB = MotorGroup();

//okapi::MotorGroup inF = MotorGroup();

/*
std::shared_ptr<OdomChassisController> drive = 
	ChassisControllerBuilder().withMotors(movement).withDimensions(okapi::AbstractMotor::gearset::green, scales).withOdometry(scales).buildOdometry();

	std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(drive->getModel());
	
	okapi::Controller controller;
*/
