#include "movements/move.hpp"

//simple lateral movement
void moveSettled(PID drivePID, PID headingPID, double distance, double maxSpeed, double timeout){
    drivePID.reset();
    headingPID.reset();
    double target = distance;
    double time = pros::millis();
    double distTravelledBefore = getForwardTrackerInchesOnEncoders();
    double angle = imu.get_heading();
    while(!drivePID.isSettled() && (fabs(pros::millis() - time) < timeout )){
        double distTravelled = getForwardTrackerInchesOnEncoders();
        double error = distance + distTravelledBefore - distTravelled;
        double angleError = imu.get_heading() - angle;
        double driveVal = drivePID.computeError(distTravelled);
        double headingVal = headingPID.computeError(angleError);
        double leftPower = std::clamp((driveVal + headingVal), -maxSpeed, maxSpeed);
        double rightPower = std::clamp((driveVal - headingVal), -maxSpeed, maxSpeed);
        tank(leftPower, rightPower);

        pros::delay(10);


    }
    tank(0,0);
}

//does not stop motors after finishing, simple laterla movement
void moveChain(PID drivePID, PID headingPID, double distance, double maxSpeed, double timeout, double exit){
    drivePID.reset();
    headingPID.reset();
    double target = distance;
    double time = pros::millis();
    double distTravelledBefore = getForwardTrackerInchesOnEncoders();
    double angle = imu.get_heading();
    while(!drivePID.isSettled() && (fabs(pros::millis() - time) < timeout )){
        double distTravelled = getForwardTrackerInchesOnEncoders();
       double error = distance + distTravelledBefore - distTravelled;
        double angleError = imu.get_heading() - angle;
        double driveVal = drivePID.computeError(distTravelled);
        double headingVal = headingPID.computeError(angleError);
        double leftPower = std::clamp((driveVal + headingVal), -maxSpeed, maxSpeed);
        double rightPower = std::clamp((driveVal - headingVal), -maxSpeed, maxSpeed);
        tank(leftPower, rightPower);
        if(fabs(error) < exit){
            break;
        }

        pros::delay(10);


    }
    
}

//2d motion with heading
void moveWithHeading(PID drivePID, PID headingPID, double distance, double targetAngle, double maxSpeed, double timeout){
    drivePID.reset();
    headingPID.reset();
    double target = distance;
    double targetang = targetAngle;
    double time = pros::millis();
    double distTravelledBefore = getForwardTrackerInchesOnEncoders();
    double angle = imu.get_heading();
    while((!drivePID.isSettled() && !headingPID.isSettled()) && (fabs(pros::millis() - time) < timeout )){
        double distTravelled = getForwardTrackerInchesOnEncoders();
        double error = distance + distTravelledBefore - distTravelled;
        double angleError = targetAngle - imu.get_heading();
        double driveVal = drivePID.computeError(distTravelled);
        double headingVal = headingPID.computeError(angleError);
        double leftPower = std::clamp((driveVal + headingVal), -maxSpeed, maxSpeed);
        double rightPower = std::clamp((driveVal - headingVal), -maxSpeed, maxSpeed);
        tank(leftPower, rightPower);

        pros::delay(10);


    }
    tank(0,0);
}

//2d motion with heading exits for chaining
void moveWithHeadingChain(PID drivePID, PID headingPID, double distance, double targetAngle, double maxSpeed, double timeout, double exit){
    drivePID.reset();
    headingPID.reset();
    double target = distance;
    double targetang = targetAngle;
    double time = pros::millis();
    double distTravelledBefore = getForwardTrackerInchesOnEncoders();
    double angle = imu.get_heading();
    while((!drivePID.isSettled() && !headingPID.isSettled()) && (fabs(pros::millis() - time) < timeout )){
        double distTravelled = getForwardTrackerInchesOnEncoders();
        double error = distance + distTravelledBefore - distTravelled;
        double angleError = targetAngle - imu.get_heading();
        double driveVal = drivePID.computeError(distTravelled);
        double headingVal = headingPID.computeError(angleError);
        double leftPower = std::clamp((driveVal + headingVal), -maxSpeed, maxSpeed);
        double rightPower = std::clamp((driveVal - headingVal), -maxSpeed, maxSpeed);
        tank(leftPower, rightPower);
        if(fabs(error) < exit){
            break;
        }
        pros::delay(10);


    }
    
}