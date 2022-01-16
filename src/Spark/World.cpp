#include "World.hpp"

#include "Level.hpp"

World::World()
{
}

World::~World()
{
    delete m_level;
}

void World::init()
{
    if (!m_level)
    {
        m_level = new Level();
        m_level->init();
    }
}

void World::handleEvent(sf::Event& event)
{
    m_level->handleEvent(event);
}

void World::update(float dt)
{
    m_level->update(dt);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states)
{
    m_level->draw(target, states);
}
