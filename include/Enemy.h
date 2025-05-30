#pragma once
#include "MobileObject.h"

class Enemy : public MobileObject
{
public:
	Enemy(sf::Vector2f location, SfmlManager& SfmlMan);
	virtual ~Enemy() = default;
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(std::vector <std::vector<std::unique_ptr<Tile>>>&, float) override;

};