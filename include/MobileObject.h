#pragma once
#include "Object.h"
#include "tile.h"

class MobileObject : public Object
{
public:
	MobileObject(sf::Vector2f location, sf::Sprite sprite);
	virtual ~MobileObject() = default;
	//virtual void move(std::vector<std::unique_ptr<Tile>>&, float) = 0;
	virtual void move(std::vector <std::vector<std::unique_ptr<Tile>>>& ,float) = 0;


protected:
	sf::Vector2f m_direction = { 0,0 };
};