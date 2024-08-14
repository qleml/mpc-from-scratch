#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "PhysicsObject.h"
#include "Renderer.h"
#include "Logger.h"
#include "Config.h"
#include <SFML/Graphics.hpp>

class Simulator
{
public:
    Simulator(PhysicsObject& physicsObj, SimulatorConfig config);
    ~Simulator();
    void run();
    void stopSimThread();
    void simThread();

private:
    PhysicsObject& _physicsObj;
    double _dt;
    double _time;
    double _duration;
    double _noiseMean;
    double _noiseStdDev;
    bool _gui;

    int _windowWidth;
    int _windowHeight;

    std::thread _simThread;
    bool _running;

    Logger _logger;
};

#endif // SIMULATOR_H