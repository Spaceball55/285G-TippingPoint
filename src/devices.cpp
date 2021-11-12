#include "comp/devices.hpp"

okapi::ChassisScales scales({3_in, 12_in}, imev5GreenTPR);

//okapi::MotorGroup movement = MotorGroup({-10,-2,11,20});

const int rightTray = -4; //arbitrary motors, change later
const int leftTray = 5;
const int hammer = 6;

//okapi::MotorGroup trayMove = MotorGroup({rightTray, leftTray});

//okapi::MotorGroup inB = MotorGroup();

//okapi::MotorGroup inF = MotorGroup();

//std::shared_ptr<okapi::Motor> rTray = std::make_shared<okapi::Motor>(rightTray, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);

okapi::Motor rTray(rightTray, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor lTray(leftTray, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);

//TrayController traycontroller = TrayController(rTray);

std::shared_ptr<OdomChassisController> chassis = 
ChassisControllerBuilder().withMotors({-10,-2}, {11, 20}).withDimensions(okapi::AbstractMotor::gearset::green, scales).withOdometry(scales, okapi::StateMode::CARTESIAN, 0_mm, 0_deg).buildOdometry();

std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());
	
okapi::Controller controller;