#include "devices.hpp"
#include "util.hpp"
#include "pose.hpp"

extern void setOdomPos(double x, double y, double theta);
extern Pose getOdomPos();
extern void initOdom();
extern Pose odomPos;
extern void odomLoop(bool isFwdTracker);
extern double getForwardTrackerInchesOnEncoders();