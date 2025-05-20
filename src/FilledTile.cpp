#include "FilledTile.h"


FilledTile::FilledTile(sf::Vector2f location, SfmlManager& SfmlMan) : Tile(location, TileType::TRAIL, sf::Color::Red, sf::Sprite{ SfmlMan.getTilesTex() })
{
}
void FilledTile::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location);
	m_sprite.setTextureRect(sf::IntRect(0, 0, SIZE::TILE_SIZE, SIZE::TILE_SIZE));
	m_sprite.setColor(m_color);
	window.draw(m_sprite);
}
