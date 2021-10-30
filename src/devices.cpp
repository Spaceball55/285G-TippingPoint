#include "comp/devices.hpp"

okapi::ChassisScales scales({3_in, 12_in}, imev5GreenTPR);

okapi::MotorGroup movement = MotorGroup({-10,-2,11,20});

//okapi::MotorGroup inB = MotorGroup();

//okapi::MotorGroup inF = MotorGroup();

std::shared_ptr<OdomChassisController> chassis = 
ChassisControllerBuilder().withMotors({-10,-2}, {11, 20}).withDimensions(okapi::AbstractMotor::gearset::green, scales).withOdometry(scales, okapi::StateMode::CARTESIAN, 0_mm, 0_deg).buildOdometry(); //add to devices


std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());
	
okapi::Controller controller;

