#pragma once
#include <SFML/Graphics.hpp>
#include "SfmlManager.h"

class Information
{
public:
	Information(SfmlManager&);

	void setTilesPerRow(int tilesPerRow) { m_tilesPerRow = tilesPerRow; }
	void setTilesPerCol(int tilesPerCol) { m_tilesPerCol = tilesPerCol; }
	void setLife(int life) { m_life = life; }
	void setNumEnemy(int numEnemy) { m_numEnemy = numEnemy; }
	void setClosePrecent(int closePrecent) { m_closePrecent = closePrecent; }

	int getTilesPerRow() const { return m_tilesPerRow; }
	int getTilesPerCol() const { return m_tilesPerCol; }
	int getLife() const { return m_life; }
	int getNumEnemy() const { return m_numEnemy; }
	int getClosePrecent() const { return m_closePrecent; }

	void draw(sf::RenderWindow&);

private:
	int m_tilesPerRow;
	int m_tilesPerCol;
	int m_life;
	int m_numEnemy;
	int m_closePrecent;
	SfmlManager& m_SfmlManager;
};