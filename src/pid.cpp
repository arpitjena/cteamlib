#include "pid.hpp"

PID::PID(double kp, double ki, double kd)
    : kp(kp), ki(ki), kd(kd), prevError(0.0), totalError(0.0) {
}

double PID::compute(double current, double target){
    double error = target - current;
    totalError += error;
    double output = kp * error + ki * totalError + kd * (error - prevError);

    prevError = error;

    return output;
}

void PID::reset(){
    totalError = 0.0;
    prevError = 0.0;
}

void PID::setConstants(double kp, double ki, double kd){
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}