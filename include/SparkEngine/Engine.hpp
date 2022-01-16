#pragma once

#include "World.hpp"

class Engine
{
public:
    Engine(class World& world);
    ~Engine();

    void init();
    void run();

private:
    sf::RenderWindow m_window;

    sf::Clock m_clock;
    sf::Time  m_dt;

    void handleEvent();
    void update();
    void draw();

private:
    World m_world;
};
