#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Tile.h"
#include "SfmlManager.h"
#include "info.h"
class GameController
{
public:
	GameController();
	void run();

private:
	SfmlManager m_sfmlManager;
	Information m_information;
	sf::RenderWindow m_window;
	std::vector<std::vector<std::unique_ptr<Object>>> m_boardGame;

	void initWindow();
	void initBoard();
	void drawBoard();
};