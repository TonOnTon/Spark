#pragma once

#include <SFML/Graphics.hpp>

class World;
class Camera;

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
    World*  m_world  = nullptr;
    Camera* m_camera = nullptr;

public:
    inline void setWorld(World& world)
    {
        m_world = &world;
    }

    inline void setCamera(Camera& camera)
    {
        m_camera = &camera;
    }

    inline World* getWorld() const
    {
        return m_world;
    }

    inline Camera* getCamera() const
    {
        return m_camera;
    }

    inline sf::Vector2i getMousePosWindow() const
    {
        return sf::Mouse::getPosition();
    }

    inline sf::Vector2i getMousePosScreen() const
    {
        return sf::Mouse::getPosition(m_window);
    }

    inline sf::Vector2f getMousePosView() const
    {
        return m_window.mapPixelToCoords(getMousePosScreen());
    }

    inline float getDt() const
    {
        return m_dt.asSeconds();
    }
};

extern Engine g_engine;