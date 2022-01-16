#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

class Level
{
public:
    Level();
    ~Level();

protected:
    virtual void init();
    virtual void handleEvent(sf::Event& event);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states);

    std::vector<class Object*> m_objects;

    friend class World;
};
