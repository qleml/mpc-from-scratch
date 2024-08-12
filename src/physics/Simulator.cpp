#include "Simulator.h"
#include "PhysicsObject.h"
#include "Logger.h" 

#include <iostream>

Simulator::Simulator(PhysicsObject& physicsObj, double dt, double duration)
    : 
    _physicsObj(physicsObj), 
    _dt(dt), 
    _duration(duration),
    _time(0.0)
{
}

Simulator::~Simulator()
{
}

void Simulator::run()
{
    std::cout << "Starting the simulation with time step " << _dt << "..." << std::endl;

    Logger logger;

    int force = 10;

    while(_time < _duration)
    {
        std::vector<double> state = _physicsObj.getState();
        logger.saveState(state, _time);
        if(_time > 10.0) force = 0;
    
        _physicsObj.update(force, _dt);
        _time += _dt;
    }
    std::cout << "Simulation complete." << std::endl; 
}
