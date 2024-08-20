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