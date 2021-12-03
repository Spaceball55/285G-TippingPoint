#include "comp/devices.hpp"

bool hammerUp = true;

void HammerController::updateState(HammerStates newHState){hState = newHState;}

void HammerController::hammerTime(){
    while(1){
        switch(hState){
            case off:
            hammer.moveVelocity(0);
            break;

            case up:
            hammer.moveAbsolute(0, 90);
            pros::delay(1000);
            hState = HammerStates::off;
            hammerUp = true;
            break;

            case down:
            hammer.moveAbsolute(90, 200);
            pros::delay(1000);
            hState=HammerStates::off;
            hammerUp=false;
            break;
        };
        pros::delay(10);
    }
}