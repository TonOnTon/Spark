#pragma once

#include "Object.hpp"

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
    class Level* m_level = nullptr;
};
