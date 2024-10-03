#include "turn.hpp"

//turn to heading
void turnToHeading(PID turnPID, double angle, double maxSpeed, double timeout){
    turnPID.reset();
    double currAngle = imu.get_heading();
    double time = pros::millis();
    while(!turnPID.isSettled() && (pros::millis() - time)< timeout){
        double getCurrAngle = imu.get_heading();
        double error = getCurrAngle - currAngle;
        double turnPower = turnPID.computeError(error);
        turnPower = std::clamp(turnPower, -maxSpeed, maxSpeed);
        tank(turnPower, -turnPower);
        pros::delay(10);
    }
    tank(0,0);
}

//turn to heading chained
void turnToPoint(PID turnPID, Pose target, double maxSpeed, double timeout){
    turnPID.reset();
    double currAngle = getOdomPos().angleError(target, false);
    double time = pros::millis();
    while(!turnPID.isSettled() && (pros::millis() - time)< timeout){
        double getCurrAngle = getOdomPos().angleError(target, false);
        double error = getCurrAngle - currAngle;
        double turnPower = turnPID.computeError(error);
        turnPower = std::clamp(turnPower, -maxSpeed, maxSpeed);
        tank(turnPower, -turnPower);
        pros::delay(10);
    }
    tank(0,0);
}