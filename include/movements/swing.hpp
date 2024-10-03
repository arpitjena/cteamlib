#include "main.h"

enum class swingType{
    LEFT,
    RIGHT
};

extern void swingToHeading(PID swingPID, double target, swingType swingtype, double maxSpeed, double timeout);
extern void swingToHeadingChain(PID swingPID, double target, swingType swingtype, double maxSpeed, double exit, double timeout);