#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "PhysicsObject.h"

class Simulator
{
public:
    Simulator(PhysicsObject& physicsObj, double dt = 0.1, double duration = 10.0);
    ~Simulator();
    void run();

private:
    PhysicsObject& _physicsObj;
    double _dt;
    double _time;
    double _duration;
};

#endif // SIMULATOR_H