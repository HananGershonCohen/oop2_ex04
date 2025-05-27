#pragma once
#include "Object.h"


class Tile : public Object
{
public:
	Tile(sf::Vector2f location, sf::Sprite sprite);
	virtual ~Tile() = default;
	virtual bool isEmpty() = 0;
	virtual bool getVisited() const { return m_visited; }
	virtual void setVisited(bool visited) { m_visited = visited; }

protected:
	
	bool m_visited = false;
	
};

