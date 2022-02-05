#pragma once

#include "Object.hpp"

#include <SFML/Graphics.hpp>

class TileMap : public Object
{
public:
    TileMap();
    ~TileMap();

    void draw(sf::RenderTarget& target, sf::RenderStates states) override;

    void load(const std::string& path);

public:
    class Tile
    {
    public:
        Tile(const sf::Vertex& vertex);

    private:
        const sf::Vertex* m_vertex;

    public:
        inline const sf::Vector2f& getPosition() const
        {
            return m_vertex[0].position;
        }
    };

private:
    sf::VertexArray m_vertices;
    sf::Texture     m_texture;

    sf::Vector2u m_tileSize;
    sf::Vector2u m_size;

public:
    inline Tile operator[](std::size_t index) const
    {
        return Tile(m_vertices[index * 2 * 3]);
    }
};
