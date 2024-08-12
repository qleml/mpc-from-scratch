#include "Simulator.h"
#include "PhysicsObject.h"

#include <iostream>

Simulator::Simulator(PhysicsObject& physicsObj, double dt, double duration)
    : 
    _physicsObj(physicsObj), 
    _dt(dt), 
    _duration(duration),
    _time(0.0)
    _window(sf::VideoMode(800, 600), "Simulation")
{
}

Simulator::~Simulator()
{
}

void Simulator::run()
{
    std::cout << "Starting the simulation with time step " << _dt << "..." << std::endl;
    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        if (_time < _duration)
        {
            std::vector<double> state = _physicsObj.getState();
            std::cout << "Position: " << state[0] << ", Velocity: " << state[1] << std::endl;
            _physicsObj.update(1, _dt);
            _time += _dt;

            _window.clear();

            sf::CircleShape shape(5);
            shape.setPosition(state[0] * 10, 300); // Scale and center the position
            shape.setFillColor(sf::Color::Green);
            _window.draw(shape);

            _window.display();
        }
        else
        {
            _window.close();
        }
    }
    std::cout << "Simulation complete." << std::endl;
}