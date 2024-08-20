#include "devices.hpp"

//chassis motors/ motor groups
pros::MotorGroup left({2,3,4});
pros::MotorGroup right({-5,-6,-7});

//intake & conveyor motor
pros::Motor intake(1);

//lift motor
pros::Motor lift(2);

//dist sensor to detect ring
pros::Distance dist(10);

//rot sensors
//trackers
pros::Rotation forwardRot(1);
pros::Rotation liftRot(2);

pros::Imu imu(7);

//controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

