#include "Simulator.h"
#include "PhysicsObject.h"
#include "Renderer.h"
#include "Config.h"

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
    _gui(config.gui),
    _time(0.0),
    _running(false)
{
}

Simulator::~Simulator()
{
    stopSimThread();
}

void Simulator::run()
{
    _running = true;
    _simThread = std::thread(&Simulator::simThread, this);

    if (_gui)
    {
        Renderer renderer(_physicsObj);
        renderer.render();
    }
}

void Simulator::simThread()
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(_noiseMean, _noiseStdDev);
        
    double force = 0;

    while (_time < _duration)
    {
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

            _logger.saveState(state, _time);

            // TODO: CONTROLLER IMPLEMENTATION

            //if (_time > _duration/2) force = 0;

            _physicsObj.update(force, _dt);
            _time += _dt;

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            double elapsed_seconds = elapsed.count();

            double sleep_time = _dt - elapsed_seconds;
            if (sleep_time > 0)
            {
                std::this_thread::sleep_for(std::chrono::duration<double>(sleep_time));
            }
        }
    }

    stopSimThread();
}

void Simulator::stopSimThread()
{
    if (_running)
    {
        _running = false;
        _simThread.join();
    }
}