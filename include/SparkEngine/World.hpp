#pragma once

#include "Object.hpp"

class Level;

class World : public Object
{
public:
    World();
    ~World();

    virtual void init() override;
    virtual void handleEvent(sf::Event& event) override;
    virtual void update(float dt) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) override;

protected:
    Level* m_level = nullptr;

public:
    inline Level* getLevel() const
    {
        return m_level;
    }

    inline void setLevel(Level* level)
    {
        m_level = level;
    }
};
