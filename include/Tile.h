#pragma once
#include "Object.h"


class Tile : public Object
{
public:
	Tile(sf::Vector2f location, TileType type, sf::Color color, sf::Sprite sprite);
	virtual ~Tile() = default;
	virtual void draw(sf::RenderWindow& window) override {};

protected:
	
	bool m_visited;
	TileType m_type;
	sf::Color m_color;
};

