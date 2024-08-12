#include "MassSpringDamper.h"
#include <iostream>
#include <mutex>
#include <vector>

MassSpringDamper::MassSpringDamper(double mass, double springConstant, double dampingCoefficient, std::vector<double> state)
    : mass(mass), springConstant(springConstant), dampingCoefficient(dampingCoefficient)
{
    setState(state);
}

MassSpringDamper::~MassSpringDamper()
{
}

void MassSpringDamper::update(double force, double dt)
{
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    double position = _state[0];
    double velocity = _state[1];
    double acceleration = (force - dampingCoefficient * velocity - springConstant * position) / mass;
    velocity += acceleration * dt;
    position += velocity * dt;
    _state[0] = position;
    _state[1] = velocity;
    _state[2] = acceleration;
}

void MassSpringDamper::setMass(double mass)
{
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    this->mass = mass;
}

void MassSpringDamper::setSpringConstant(double springConstant)
{
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    this->springConstant = springConstant;
}

void MassSpringDamper::setDampingCoefficient(double dampingCoefficient)
{
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    this->dampingCoefficient = dampingCoefficient;
}

double MassSpringDamper::getMass() const
{
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    return mass;
}

double MassSpringDamper::getSpringConstant() const
{
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    return springConstant;
}

double MassSpringDamper::getDampingCoefficient() const
{
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    return dampingCoefficient;
}
