#pragma once
#include "MobileObject.h"

class Player : public MobileObject
{
public:
	Player(sf::Vector2f location, SfmlManager& SfmlMan);
	virtual ~Player() = default;
	virtual void draw(sf::RenderWindow&) override;
	virtual void move(std::vector<std::vector<std::unique_ptr<Tile>>>&, float) override;

private:

	void ArrangeLocation(sf::Vector2f);
	SfmlManager& m_SfmlMan;


};