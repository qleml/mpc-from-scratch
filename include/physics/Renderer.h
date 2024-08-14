#ifndef RENDERER_H
#define RENDERER_H

#include "PhysicsObject.h"
#include <SFML/Graphics.hpp>

#include <thread>

class Renderer
{
public:
    Renderer(PhysicsObject& physicsObj);
    ~Renderer();
    void render();


private:
    PhysicsObject& _physicsObj;
    sf::RenderWindow _window;
};

#endif // RENDERER_H