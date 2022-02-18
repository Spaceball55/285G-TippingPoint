#include "comp/devices.hpp"

std::shared_ptr<okapi::AsyncPositionController<double, double>> trayController = 
AsyncPosControllerBuilder().withMotor(lTray).build();

std::shared_ptr<okapi::AsyncPositionController<double, double>> fbController =
AsyncPosControllerBuilder().withMotor(20).build();

std::shared_ptr<okapi::AsyncPositionController<double, double>> clawController =
AsyncPosControllerBuilder().withMotor(claw).build();

bool td = true;

bool clawD = false;

const int h0 = 0;
const int h1 = 90;

const int fbh0 = 0;
const int fbh1 = 100;

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

void clawUp(){
    clawController->setTarget(h1);
}

void clawDown(){
    clawController->setTarget(h0);
}

void FourBar::clawToggle(){
    if(clawButton.changedToPressed()){
        if(clawD) clawUp();
        else clawDown();

        clawD != clawD;
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