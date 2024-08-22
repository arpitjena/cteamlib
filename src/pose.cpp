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
    double dist = sqrt(double(((second.x - this->x)^2) + ((second.y - this->x)^2)));
}

double Pose::angleError(Pose second, bool isRadian){

}