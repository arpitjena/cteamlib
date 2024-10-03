#include "main.h"

extern void moveSettled(PID drivePID, PID headingPID, double distance, double maxSpeed, double timeout);
extern void moveChain(PID drivePID, PID headingPID, double distance, double maxSpeed, double timeout, double exit);
extern void moveWithHeading(PID drivePID, PID headingPID, double distance, double targetAngle, double maxSpeed, double timeout);
extern void moveWithHeadingChain(PID drivePID, PID headingPID, double distance, double targetAngle, double maxSpeed, double timeout, double exit);