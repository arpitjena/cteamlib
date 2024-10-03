#include "swing.hpp"

//regular swing
void swingToHeading(PID swingPID, double target, swingType swingtype, double maxSpeed, double timeout){
    swingPID.reset();
    double currAngle = imu.get_heading();
    double time = pros::millis();
    while(!swingPID.isSettled() && (pros::millis() - time)< timeout){
        double getCurrAngle = imu.get_heading();
        double error = getCurrAngle - currAngle;
        double turnPower = swingPID.computeError(error);
        turnPower = std::clamp(turnPower, -maxSpeed, maxSpeed);
        if(swingtype == swingType::LEFT){
            tank(0,turnPower);
        } else{
            tank(turnPower, 0);
        }
        pros::delay(10);
    }
    tank(0,0);
}

//swing with chain
void swingToHeadingChain(PID swingPID, double target, swingType swingtype, double maxSpeed, double exit, double timeout){
    swingPID.reset();
    double currAngle = imu.get_heading();
    double time = pros::millis();
    while(!swingPID.isSettled() && (pros::millis() - time)< timeout){
        double getCurrAngle = imu.get_heading();
        double error = getCurrAngle - currAngle;
        double turnPower = swingPID.computeError(error);
        turnPower = std::clamp(turnPower, -maxSpeed, maxSpeed);
        if(swingtype == swingType::LEFT){
            tank(0,turnPower);
        } else{
            tank(turnPower, 0);
        }
        if(fabs(error) < exit){
            break;
        }
        pros::delay(10);
    }
    //stall
}