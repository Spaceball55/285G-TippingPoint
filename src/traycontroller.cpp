#include "comp/devices.hpp"

std::shared_ptr<okapi::AsyncPositionController<double, double>> trayController = 
AsyncPosControllerBuilder().withMotor(lTray).build();

std::shared_ptr<okapi::AsyncPositionController<double, double>> fbController =
AsyncPosControllerBuilder().withMotor(fbMotor).build();

std::shared_ptr<okapi::AsyncPositionController<double, double>> clawController =
AsyncPosControllerBuilder().withMotor(claw).build();

bool td = true;

bool clawD = true;

int currentHeight = fbMotor.getPosition();

const int h0 = 0;
const int h1 = 900;

const int fbh0 = 0;
const int fbh1 = -1000;

const int clawh0 = 100;
const int clawh1 = -100;

bool fbd = false;

//functions

void TwoBar::lift(){
    if(trayButton.changedToPressed()){
        if(td) trayUp();
        else trayDown();
        td != td;
    }
};

void trayUp(){
    trayController->setTarget(h1);
    td = true;
}

void trayDown(){
    trayController->setTarget(h0);
    td = false;
}

void fbUp(){
    fbController->setTarget(fbh1);

}

void fbDown(){
    fbController->setTarget(fbh0);
}

void clawUp(){
    clawController->setTarget(h0);
    //clawD = false;
}

void clawDown(){
    clawController->setTarget(h1);
    //clawD = true;
}

void FourBar::lift(){
    fbMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

    if(fourBarUpButton.changedToPressed()){
        fbMotor.moveVelocity(150);
    }
    else if(fourBarDownButton.changedToPressed()){
        fbMotor.moveVelocity(-150);
    }
    else {
        fbMotor.moveVelocity(0);
    }
    currentHeight = fbMotor.getPosition();
}

void FourBar::clawToggle(){
    if(clawButton.changedToPressed()){
        clawD = !clawD;
        if(clawD) clawController->setTarget(clawh1);
        else clawController->setTarget(clawh0);
        //else if(!clawD) clawController->setTarget(clawh0);
        //else claw.moveVelocity(0);
    }
}

/*
void TrayController::setNewState(TrayStates newState){state = newState;}

void TrayController::trayMovement(){
    while(1){
        switch(state){
            case off: //this is the case for when we want to turn off the tray
            //rTray.moveVelocity(0);
            lTray.moveVelocity(0);
            break;

            case up: //putting the tray into "up" position
            //rTray.moveAbsolute(360, 60);
            lTray.moveAbsolute(90, 60); //todo: merge ltray and rtray 
            pros::delay(1000);
            state = TrayStates::off;
            trayUp = true;
            break;

            case down: //tray into "down position"
            //rTray.moveAbsolute(0, 60);
            lTray.moveAbsolute(0, 60); //todo: check what position 0 is for motors (it could be the "up" position — if so, we will flip flop)
            pros::delay(1000);`                                                                 1111111
            state = TrayStates::off;
            trayUp = false;
            break;
        };
        pros::delay(10);
    }
}

*/