#include "main.h"
#include "comp/devices.hpp"

void winPoint(){
    move(autoChassis, 0.1_ft, fwd);
  
  autChassis->turnAngle(315);
  move(autoChassis, 3_ft, bwd);
  autChassis->turnAngle(45);
  move(autoChassis, 8_ft, bwd);
  trayUp();
  belt.moveVelocity(-600);
  pros::delay(2500);
  belt.moveVelocity(0);
  trayDown();
  move(autoChassis, 0.1_ft, fwd);
}
