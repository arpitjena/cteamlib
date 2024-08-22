#include "main.h"
#include "util.hpp"

class PID{
    public:

    PID::PID(double kp, double ki, double kd);
    double computeError(double error);
    double compute(double current, double target);
    void reset();
    void setConstants(double kp, double ki, double kd);
    private:
        double kp;
        double ki; 
        double kd;
        double starti;
        double smallDist;
        double smallTimeout;
        double bigDist;
        double bigTimeout;
        double totalError;
        double prevError;
        double error;
};