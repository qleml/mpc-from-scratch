#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "PhysicsObject.h"
#include "Config.h"
#include <SFML/Graphics.hpp>

class Simulator
{
public:
    Simulator(PhysicsObject& physicsObj, SimulatorConfig config);
    ~Simulator();
    void run();

private:
    PhysicsObject& _physicsObj;
    double _dt;
    double _time;
    double _duration;
    int _windowWidth;
    int _windowHeight;
    double _noiseMean;
    double _noiseStdDev;
    sf::RenderWindow _window;
};

#endif // SIMULATOR_H