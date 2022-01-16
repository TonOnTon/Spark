#pragma once

#include "Level.hpp"

class World
{
public:
    World();
    ~World();

protected:
    virtual void init();
    virtual void handleEvent(sf::Event& event);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states);

    class Level* m_level = nullptr;

private:
    Level m_defaultLevel;

    friend class Engine;
};
