#include "TileMap.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

TileMap::TileMap()
{
}

TileMap::~TileMap()
{
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states)
{
    states.transform *= getTransform();

    states.texture = &m_texture;

    target.draw(m_vertices, states);
}

void TileMap::load(const std::string& path)
{
    std::ifstream tilesetData("assets/maps/" + path);
    std::cout << std::filesystem::current_path() << "\n";

    std::string texturePath;
    tilesetData >> texturePath;

    tilesetData >> m_tileSize.x;
    tilesetData >> m_tileSize.y;

    tilesetData >> m_size.x;
    tilesetData >> m_size.y;

    m_texture.loadFromFile("assets/textures/" + texturePath);

    m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    m_vertices.resize(m_size.x * m_size.y * 2 * 3);

    for (unsigned int i = 0; i < m_size.x; ++i)
        for (unsigned int j = 0; j < m_size.y; ++j)
        {
            int tileNumber;
            tilesetData >> tileNumber;

            int tu = tileNumber % (m_texture.getSize().x / m_tileSize.x);
            int tv = tileNumber / (m_texture.getSize().x / m_tileSize.x);

            sf::Vertex* quad = &m_vertices[(i + j * m_size.x) * 2 * 3];
                
            quad[0].position = sf::Vector2f(i * m_tileSize.x, j * m_tileSize.y);
            quad[1].position = sf::Vector2f(i * m_tileSize.x, (j + 1) * m_tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * m_tileSize.x, (j + 1) * m_tileSize.y);
            
            quad[3].position = quad[0].position;
            quad[4].position = sf::Vector2f((i+1) * m_tileSize.x, j * m_tileSize.y);
            quad[5].position = quad[2].position;

            quad[0].texCoords = sf::Vector2f(tu * m_tileSize.x, tv * m_tileSize.y);
            quad[1].texCoords = sf::Vector2f(tu * m_tileSize.x, (tv + 1) * m_tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, (tv+1) * m_tileSize.y);
            
            quad[3].texCoords = quad[0].texCoords;
            quad[4].texCoords = sf::Vector2f((tu+1) * m_tileSize.x, tv * m_tileSize.y);
            quad[5].texCoords = quad[2].texCoords;
        }
}

TileMap::Tile::Tile(const sf::Vertex& vertex) : m_vertex(&vertex)
{
}
