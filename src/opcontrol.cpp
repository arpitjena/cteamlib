#include "opcontrol.hpp"

void tank(double leftVals, double rightVals){
    left.move(leftVals);
    right.move(rightVals);
    
}

void arcade(double throttle, double turn){
    left.move(throttle + turn);
    right.move(throttle - turn);
}