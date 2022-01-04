#include "Engine.hpp"

Engine::Engine() : m_window(sf::VideoMode(200, 200), "Engine")
{
}

Engine::~Engine()
{
}

void Engine::run()
{
    while (m_window.isOpen())
    {
        m_dt = m_clock.restart();

        handleEvent();
        update();
        draw();
    }
}

void Engine::handleEvent()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::EventType::Closed)
            m_window.close();
    }
}

void Engine::update()
{
}

void Engine::draw()
{
    m_window.clear();

    m_window.display();
}
