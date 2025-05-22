#pragma once


enum class TileType
{
	EMPTY,     // ���� ������ �� ����
	FILLED,    // ���� ���� ���� (���� �����)
	BORDER,    // ���� ���� �� ����
	TRAIL,  // ���� ����� ���� �����
};

namespace SIZE
	{
	 // tile = 20pixel * 20pixel
	constexpr int TILE_SIZE = 18; // size of each tile in pixels
	constexpr int HalfPixelSize = TILE_SIZE / 2;
	constexpr int TOOLBAR_SIZE = 50; // size of the toolbar in pixels
} // namespace Size