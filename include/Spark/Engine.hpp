#pragma once

#include <SFML/Graphics.hpp>

class Engine
{
public:
    Engine();
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
    class World* m_world = nullptr;
};
