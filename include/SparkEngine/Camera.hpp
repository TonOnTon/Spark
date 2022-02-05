#pragma once

#include "Object.hpp"

#include <SFML/Graphics/View.hpp>

class Camera : public Object
{
public:
    Camera();
    ~Camera();

protected:
    sf::View m_view;

public:
    inline const sf::View& getView() const
    {
        return m_view;
    }
};
