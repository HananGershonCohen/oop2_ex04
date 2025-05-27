#pragma once 
#include "Tile.h"

class EmptyTile : public Tile
{
public:
	EmptyTile(sf::Vector2f location, SfmlManager& SfmlMan);
	virtual ~EmptyTile() = default;
	virtual void draw(sf::RenderWindow&) override;
	virtual bool isEmpty() override { return true; } // EmptyTile is empty

private:

};