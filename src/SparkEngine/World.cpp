#include "World.hpp"

#include "Level.hpp"

#include <cassert>

World::World()
{
}

World::~World()
{
}

void World::init()
{
    assert(m_level, "No level");
    m_level->init();
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
