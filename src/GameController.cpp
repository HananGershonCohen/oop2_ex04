#include "GameController.h"
#include "EmptyTile.h"
#include "FilledTile.h"
#include "TrailTile.h"
#include "Utility.h"
#include <fstream>
#include <iostream>
#include <string>

GameController::GameController() 
{
	initWindow();
	initBoard();
	
}

void GameController::run()
{
	

	// width . height

	while (m_window.isOpen())
	{

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}
		m_window.clear(sf::Color::Black);
		drawBoard();
	}
}

void GameController::initWindow()
{
	std::fstream file("def.txt");
	if (!file.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return;
	}

	int rows, cols;
	file >> rows >> cols;
	m_information.setTilesPerRow(rows);
	m_information.setTilesPerCol(cols);
	int WidthWindow = SIZE::TILE_SIZE * cols;
	int HeightWindow = SIZE::TILE_SIZE * rows;
	m_window.create(sf::VideoMode(WidthWindow, HeightWindow), "Game Xonix!");
	m_window.setFramerateLimit(60);
}

void GameController::initBoard()
{
	// I want to line the board with empty tiles and the frame with solid tiles.
	int col = m_information.getTilesPerCol();
	int row = m_information.getTilesPerRow();

	m_boardGame.resize(col);
	for (int i = 0; i < col; ++i)
	{
		m_boardGame[i].resize(row);
		for (int j = 0; j < row; ++j)
		{
			if (i == 0 || i == col - 1 || j == 0 || j == row - 1)
			{
				m_boardGame[i][j] = std::make_unique<FilledTile>(sf::Vector2f(i * SIZE::TILE_SIZE, j * SIZE::TILE_SIZE),m_sfmlManager);
			}
			else
			{
				m_boardGame[i][j] = std::make_unique<EmptyTile>(sf::Vector2f(i * SIZE::TILE_SIZE, j * SIZE::TILE_SIZE), m_sfmlManager );
			}
		}
	}

}

void GameController::drawBoard()
{
	for (int i = 0; i < m_information.getTilesPerCol(); ++i)
	{
		for (int j = 0; j < m_information.getTilesPerRow(); ++j)
		{
			m_boardGame[i][j]->draw(m_window);
		}
	}
	m_window.display();
}

