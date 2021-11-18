#include "comp/devices.hpp"

bool trayUp = true; //assuming we start with the tray in "up" position

void TrayController::setState(TrayStates newState){state = newState;}

void TrayController::trayMovement(){
    while(1){
        switch(state){
            case off: //this is the case for when we want to turn off the tray
            rTray.moveVelocity(0);
            lTray.moveVelocity(0);
            break;

            case up: //putting the tray into "up" position
            rTray.moveAbsolute(360, 60);
            lTray.moveAbsolute(360, 60); //todo: merge ltray and rtray 
            pros::delay(1000);
            state = TrayStates::off;
            trayUp = true;
            break;

            case down: //tray into "down position"
            rTray.moveAbsolute(0, 60);
            lTray.moveAbsolute(0, 60); //todo: check what position 0 is for motors (it could be the "up" position — if so, we will flip flop)
            pros::delay(1000);
            state = TrayStates::off;
            trayUp = false;
            break;
        };
        pros::delay(10);
    }
}