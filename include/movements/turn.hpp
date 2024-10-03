#include "main.h"

extern void turnToHeading(PID turnPID, double angle, double maxSpeed, double timeout);
extern void turnToPoint(PID turnPID, Pose target, double maxSpeed, double timeout);