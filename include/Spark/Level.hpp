#pragma once

#include "Object.hpp"

#include <vector>

class Level : public Object
{
public:
    Level();
    ~Level();

    virtual void init() override;
    virtual void handleEvent(sf::Event& event) override;
    virtual void update(float dt) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) override;

protected:
    std::vector<Object*> m_objects;
};
