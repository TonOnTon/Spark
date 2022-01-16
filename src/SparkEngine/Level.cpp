#include "Level.hpp"

#include "Object.hpp"

Level::Level()
{
}

Level::~Level()
{
    for (auto object : m_objects)
    {
        delete object;
    }
}

void Level::init()
{
    for (auto object : m_objects)
    {
        object->init();
    }
}

void Level::handleEvent(sf::Event& event)
{
    for (auto object : m_objects)
    {
        object->handleEvent(event);
    }
}

void Level::update(float dt)
{
    for (auto object : m_objects)
    {
        object->update(dt);
    }
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states)
{
    for (auto object : m_objects)
    {
        object->draw(target, states);
    }
}
