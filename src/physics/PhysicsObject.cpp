#include "PhysicsObject.h"

#include <vector>
#include <mutex>
#include <iostream>

PhysicsObject::PhysicsObject() : _state(3, 0.0)
{
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::setState(const std::vector<double>& state)
{
    std::lock_guard<std::mutex> lock(_mutex); // Lock the mutex
    _state = state;
}

std::vector<double> PhysicsObject::getState() const
{
    std::lock_guard<std::mutex> lock(_mutex); // Lock the mutex
    return _state;
}

void PhysicsObject::update(double force, double dt)
{
    std::cout << "Make sure to implement the update method in the derived class!" << std::endl;
}