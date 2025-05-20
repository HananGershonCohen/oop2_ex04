#include "Tile.h"

Tile::Tile(sf::Vector2f location, TileType type, sf::Color color ,sf::Sprite sprite) : Object(location, sprite), m_visited(false), m_type(type), m_color(color) 
{
}

//
//void Tile::draw(sf::RenderWindow& window) const
//{
//	sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f)); // Create a rectangle shape with size 50x50
//	rectangle.setFillColor(m_color);
//	rectangle.setPosition(m_location);
//	window.draw(rectangle);
//}
