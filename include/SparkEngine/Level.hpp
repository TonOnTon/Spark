#pragma once

#include <SFML/Graphics/RenderStates.hpp>
#include <vector>

namespace sf
{
class Event;
class RenderTarget;
} // namespace sf

class Level
{
public:
    Level();
    ~Level();

    virtual void init();
    virtual void handleEvent(sf::Event& event);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states);

private:
    std::vector<class Object*> m_objects;
};
