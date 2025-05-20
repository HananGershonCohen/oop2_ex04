#include "TrailTile.h"

TrailTile::TrailTile(sf::Vector2f location, SfmlManager& SfmlMan) : Tile(location, TileType::TRAIL , sf::Color::Red , sf::Sprite{ SfmlMan.getTilesTex()})
{}

void TrailTile::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location);
	m_sprite.setTextureRect(sf::IntRect(SIZE::TILE_SIZE * 3, 0, SIZE::TILE_SIZE, SIZE::TILE_SIZE));
	m_sprite.setColor(m_color);
	window.draw(m_sprite);
}
