#include "pose.hpp"

Pose::Pose(double x, double y, double theta){
    this->x = x;
    this->y = y;
    this->theta = theta;
}

Pose::Pose(double x, double y){
    this->x = x;
    this->y = y;
}

double Pose::distance(Pose second){
    double dist = sqrt(pow((second.x - this->x),2) + pow((second.y - this->y),2));
    return dist;
}
double Pose::angleError(Pose second, bool isRadian){
    double angleError = atan2(second.y, second.x) - atan2(this->y, this->x);
    if(isRadian){
        return angleError;
    } else{
        return radToDeg(angleError);
    }
    
}