#pragma once

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <vector>

namespace sf
{
class Event;
class RenderTarget;
} // namespace sf

class Object : public sf::Transformable
{
public:
    Object();
    ~Object();

    virtual void init(){};
    virtual void handleEvent(sf::Event& event){};
    virtual void update(float dt){};
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states){};
};
