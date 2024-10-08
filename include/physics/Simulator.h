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

private:

    void _computeManualDisturbance(sf::Vector2i mousePos, double &force, std::vector<double> state);

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

    sf::RenderWindow _window;

    Logger _logger;
};

#endif // SIMULATOR_H