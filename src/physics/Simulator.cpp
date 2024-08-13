#include "Simulator.h"
#include "PhysicsObject.h"
#include "Logger.h" 
#include "Config.h"

#include <SFML/Graphics.hpp>

#include <chrono>
#include <iostream>
#include <random>
#include <thread>


Simulator::Simulator(PhysicsObject& physicsObj, SimulatorConfig config)
    : 
    _physicsObj(physicsObj), 
    _dt(config.timeStep), 
    _duration(config.duration),
    _noiseMean(config.noiseMean),
    _noiseStdDev(config.noiseStdDev),
    _time(0.0),
    _window(sf::VideoMode(800, 600), "Simulation")
{
}

Simulator::~Simulator()
{
}

void Simulator::run()
{
    std::cout << "Starting the simulation with time step " << _dt << "..." << std::endl;

    Logger logger;
    int force = 0;

    sf::CircleShape shape(10.0f); // Radius of 10 units
    shape.setFillColor(sf::Color::White);

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(_noiseMean, _noiseStdDev);

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
            auto start = std::chrono::high_resolution_clock::now();

            std::vector<double> state = _physicsObj.getState();

            std::vector<double> noise(state.size());
            for (double& n : noise) {
                n = distribution(generator);
            }
    
            // TODO EIGEN
            for (size_t i = 0; i < state.size(); ++i) {
                state[i] += noise[i];
            }

            logger.saveState(state, _time);

            // TODO: CONTROLLER IMPLEMENTATION

            //if (_time > _duration/2) force = 0;

            _physicsObj.update(force, _dt);
            _time += _dt;

            if (state.size() >= 1) // Assuming state[0] is x
            {
                float fixedY = 300.0f;
                double offsetX = 400.0;
                shape.setPosition(static_cast<float>(offsetX + state[0]), fixedY);
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            double elapsed_seconds = elapsed.count();

            double sleep_time = _dt - elapsed_seconds;
            if (sleep_time > 0)
            {
                std::this_thread::sleep_for(std::chrono::duration<double>(sleep_time));
            }
        }

        _window.clear();
        _window.draw(shape);
        _window.display();
    }

    std::cout << "Simulation complete." << std::endl; 
}