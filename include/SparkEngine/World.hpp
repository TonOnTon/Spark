#pragma once

#include <SFML/Graphics/RenderStates.hpp>

namespace sf
{
class Event;
class RenderTarget;
} // namespace sf

class World
{
public:
    World();
    ~World();

    virtual void init();
    virtual void handleEvent(sf::Event& event);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states);

protected:
    class Level* m_level = nullptr;
};
