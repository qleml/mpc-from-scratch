#include "Renderer.h"
#include <PhysicsObject.h>
#include <SFML/Graphics.hpp>

#include <thread>

Renderer::Renderer(PhysicsObject& physicsObj)
    : _window(sf::VideoMode(800, 600), "Simulation"),
    _physicsObj(physicsObj)
{
}

Renderer::~Renderer()
{
}

void Renderer::render()
{
    sf::CircleShape shape(10.0f); // Radius of 10 units
    shape.setFillColor(sf::Color::White);

    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        std::vector<double> state = _physicsObj.getState();

        shape.setPosition(state[0], state[1]);
    
        _window.clear();
        _window.draw(shape);
        _window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

