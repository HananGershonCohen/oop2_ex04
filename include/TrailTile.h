#pragma once
#include "Tile.h"


class TrailTile : public Tile
{
public:
	TrailTile(sf::Vector2f location , SfmlManager& SfmlMan);
	virtual ~TrailTile() = default;
	virtual void draw(sf::RenderWindow&) override;
	virtual bool isEmpty() override { return false; } // TrailTile is not empty
};
