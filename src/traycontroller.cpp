#include "comp/devices.hpp"

std::shared_ptr<okapi::AsyncPositionController<double, double>> trayController = 
    AsyncPosControllerBuilder().withMotor(lTray).build();

bool td = true;

const int h0 = 0;
const int h1 = 1000;

void trayUp(){
    trayController->setTarget(h1);
    td = true;
}

void trayDown(){
    trayController->setTarget(h0);
    td = false;
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