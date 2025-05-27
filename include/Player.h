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
	bool m_inTrailMode = false;
	bool m_needToDoRecursion = false;

	SfmlManager& m_SfmlMan;
	void updateNewLoc(std::vector <std::vector<std::unique_ptr<Tile>>>&, sf::Vector2f);
	void ArrangeLocation(sf::Vector2f&);
	void FloodFillRec(std::vector <std::vector<std::unique_ptr<Tile>>>&,int, int);
	void updateSigns(std::vector <std::vector<std::unique_ptr<Tile>>>&);
	void cleanSigns(std::vector <std::vector<std::unique_ptr<Tile>>>&);
};