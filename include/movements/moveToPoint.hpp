#include "main.h"

struct moveToPointParams{
    bool forward;
    double maxSpeed = 127;
    double exitRange = 1;
    bool thru = false;


};

extern void moveToPoint(PID drivePID, PID turnPID, Pose target, moveToPointParams moveParams);