#include "odom.hpp"

const double trackerWheelSize = 2;
const double wheelSize = 2.75;

double getForwardTrackerInchesOnRot(){
    double currPos = forwardRot.get_position();
    double convertedPos = currPos/(M_PI * trackerWheelSize);
    return convertedPos;
}

double getForwardTrackerInchesOnEncoders(){
    double currPos = (left.get_position() + right.get_position()) / 2;
    double convertedPos = currPos/(M_PI * wheelSize);
    return convertedPos;
}

double getHeading(bool inRadians){
    if(inRadians){
        return degToRad(imu.get_heading());
    } else{
        return imu.get_heading();
    }
}

Pose odomPos = Pose(0,0,0);

void setOdomPos(double x, double y, double theta){
    odomPos = Pose(x,y,theta);
}
Pose getOdomPose(){
    return odomPos;
}

void initOdom(bool wait, double time){
    left.tare_position();
    right.tare_position();
    imu.reset();
    forwardRot.reset();
    if(wait){
        pros::delay(time);
    } 
}

void odomLoop(bool isFwdTracker){
    double currfwd;
    double currHorz;
    double currAngle;
    double deltafwd;
    double deltaHorz;
    double deltaAngle;
    double prevfwd;
    double prevHorz;
    double prevAngle;
    while(true){
        //track current vals
        if(isFwdTracker){
            currfwd = getForwardTrackerInchesOnRot();
        } else{
            currfwd = getForwardTrackerInchesOnEncoders();
        }
        double currAngle = getHeading(true);

        //create deltas
        deltafwd = currfwd - prevfwd;
        deltaAngle = currAngle - prevAngle;

        //locals
        odomPos.x += deltafwd * sin(deltaAngle);
        odomPos.y += deltafwd * cos(deltaAngle);
        odomPos.theta = getHeading(false);

        //set prevs to currs
        prevfwd = currfwd;
        prevAngle = currAngle;

        //delay
        pros::delay(10);
    }
}