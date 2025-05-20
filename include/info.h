#pragma once

class Information
{
public:
	Information() = default;
	void setTilesPerRow(int tilesPerRow) { m_tilesPerRow = tilesPerRow; }
	void setTilesPerCol(int tilesPerCol) { m_tilesPerCol = tilesPerCol; }
	int getTilesPerRow() const { return m_tilesPerRow; }
	int getTilesPerCol() const { return m_tilesPerCol; }

private:
	int m_tilesPerRow;
	int m_tilesPerCol;
};