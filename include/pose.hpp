#include "main.h"
#include "util.hpp"

class Pose{
    public:
        Pose(double x, double y);
        Pose(double x, double y, double theta);
        double distance(Pose second);
        double angleError(Pose second, bool isRadian = true);
        double x;
        double y;
        double theta;
    
        
};