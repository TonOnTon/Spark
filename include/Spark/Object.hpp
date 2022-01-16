#pragma once

#include <SFML/Graphics.hpp>

class Object : public sf::Transformable
{
public:
    Object();
    ~Object();

    virtual void init()                                                  = 0;
    virtual void handleEvent(sf::Event& event)                           = 0;
    virtual void update(float dt)                                        = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) = 0;
};
