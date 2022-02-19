#include "comp/devices.hpp"

okapi::ControllerButton trayButton = okapi::ControllerDigital::R1;

okapi::ControllerButton fourBarUpButton = okapi::ControllerDigital::A;

okapi::ControllerButton fourBarDownButton = okapi::ControllerDigital::B;

okapi::ControllerButton intakeButton = okapi::ControllerDigital::R2;

okapi::ControllerButton clawButton = okapi::ControllerDigital::L1;


okapi::ChassisScales scales({3_in, 12_in}, imev5GreenTPR);

//okapi::MotorGroup movement = MotorGroup({-10,-2,11,20});

const int frontLeftWheel = 1;
const int backLefttWheel = 11;
const int frontRightWheel = -10;
const int backRightWheel = -20;

const int clawPort = -9;

//const int rightTray = -4;
const int leftTray = -1;
const int fbSlot = -2;
//const int intakeMotor = 20;
const int beltMotor = 19; 


static std::shared_ptr<Logger> trayLog = okapi::Logger::getDefaultLogger();


//okapi::MotorGroup trayMove = MotorGroup({rightTray, leftTray});

///std::shared_ptr<okapi::Motor> rTray = std::make_shared<okapi::Motor>(rightTray, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);

//okapi::Motor rTray(rightTray, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor lTray(leftTray, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
//okapi::Motor hammer(hammerSlot, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
//okapi::Motor intake(intakeMotor, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor belt(beltMotor, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor claw(clawPort);
okapi::Motor fbMotor(fbSlot);
//TrayController traycontroller = TrayController(rTray);

std::shared_ptr<OdomChassisController> chassis = 
ChassisControllerBuilder().withMotors({-10,-2}, {11, 12}).withDimensions(okapi::AbstractMotor::gearset::green, scales).withOdometry(scales, okapi::StateMode::CARTESIAN, 0_mm, 0_deg).buildOdometry();


std::shared_ptr<OdomChassisController> autChassis = 
	ChassisControllerBuilder().withMotors({-10,-2}, {11, 20}).withDimensions(okapi::AbstractMotor::gearset::green, scales).withMaxVelocity(100).withOdometry(scales, okapi::StateMode::CARTESIAN, 0_mm, 0_deg).buildOdometry();


std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());
	
okapi::Controller controller;

std::shared_ptr<AsyncMotionProfileController> traySpinner =
  AsyncMotionProfileControllerBuilder()
    .withLimits({
      1.0, // Maximum linear velocity of the Chassis in m/s
      5.0, // Maximum linear acceleration of the Chassis in m/s/s
      10.0 // Maximum linear jerk of the Chassis in m/s/s/s
    })
    .withOutput(chassis)
    .buildMotionProfileController();

