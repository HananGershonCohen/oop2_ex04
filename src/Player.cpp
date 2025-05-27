#include "Player.h"
#include "TrailTile.h"
#include "SfmlManager.h"
#include "FilledTile.h"

Player::Player(sf::Vector2f location, SfmlManager& SfmlMan) :m_SfmlMan(SfmlMan), MobileObject(location, sf::Sprite{ SfmlMan.getTilesTex() })
{
}

void Player::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location);
	m_sprite.setTextureRect(sf::IntRect(SIZE::TILE_SIZE * 1, 0, SIZE::TILE_SIZE, SIZE::TILE_SIZE));
	window.draw(m_sprite);
}

void Player::move(std::vector <std::vector<std::unique_ptr<Tile>>>& board, float deltaTime)
{
	// Handle player movement here
	// Example: m_location += speed * deltaTime;
	
	

	//1. choose direction
	sf::Vector2f nextLoc = m_location;
	sf::Vector2f newDirection{ 0,0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{              
		newDirection.y -= 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		newDirection.y += 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		newDirection.x -= 1;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		newDirection.x += 1;
	}

	float speed = 100;
	
	// 2. if user changed directioin: update location on the Tile. 
	if (m_direction != newDirection ) 
	{

		m_direction = newDirection;
		ArrangeLocation(nextLoc);
	}

	
	nextLoc += newDirection * deltaTime * speed;
	// if newLoc into board do:
	// m_location = nextLoc;
	



	// this functin will update the board.
	// loc of player. loc of TrailTile. closed-filed
	updateNewLoc(board, nextLoc);
	
	
	m_location = nextLoc;
}

void Player::ArrangeLocation(sf::Vector2f& loc)
{
	int newX = static_cast<int>(loc.x + SIZE::HalfPixelSize) / SIZE::TILE_SIZE;
	int newY = static_cast<int>(loc.y + SIZE::HalfPixelSize) / SIZE::TILE_SIZE;
	newX *= SIZE::TILE_SIZE;
	newY *= SIZE::TILE_SIZE;
	loc =  sf::Vector2f{ static_cast<float>(newX), static_cast<float>(newY) };
}

void Player::FloodFillRec(std::vector<std::vector<std::unique_ptr<Tile>>>& board, int row, int col)
{
	if (row < 0 || row >= board.size() || col < 0 || col >= board[row].size())
		return; // Out of bounds

	if (board[row][col]->getVisited())
		return; // Already visited



	board[row][col]->setVisited(true); // Mark the tile as visited



	FloodFillRec(board, row - 1, col); // up
	FloodFillRec(board, row + 1, col); // down
	FloodFillRec(board, row, col - 1); // left
	FloodFillRec(board, row, col + 1); // right
}

void Player::updateSigns(std::vector<std::vector<std::unique_ptr<Tile>>>& board)
{
	for (int row = 0; row < board.size(); ++row)
	{
		for (int col = 0; col < board[row].size(); ++col)
		{
			if (board[row][col]->getVisited())
				board[row][col] = std::make_unique<FilledTile>(sf::Vector2f(row * SIZE::TILE_SIZE, col * SIZE::TILE_SIZE), m_SfmlMan);
		}
	}
}

void Player::cleanSigns(std::vector<std::vector<std::unique_ptr<Tile>>>& board)
{
	for (int row = 0; row < board.size(); ++row)
	{
		for (int col = 0; col < board[row].size(); ++col)
		{
			if (board[row][col]->getVisited())
			{
				board[row][col]->setVisited(false); // Reset visited status
			}
		}
	}
}

void Player::updateNewLoc(std::vector <std::vector<std::unique_ptr<Tile>>>& board, sf::Vector2f nextLoc)
{
	int row = static_cast<int>(nextLoc.x / SIZE::TILE_SIZE);
	int col = static_cast<int>(nextLoc.y / SIZE::TILE_SIZE);
	
	// if i stand on 
	//  update m_inTrailMode = true



	// if the m_location on the FilledTile, and nextLoc will on EmptyTile, then change the m_inTrailMode to true.
	if (!board[m_location.x / SIZE::TILE_SIZE][m_location.y / SIZE::TILE_SIZE]->isEmpty() &&
		(board[nextLoc.x / SIZE::TILE_SIZE][nextLoc.y / SIZE::TILE_SIZE]->isEmpty())) // meet empty
		m_inTrailMode = true;

	
	// if the m_location on the EmptyTile, and nextLoc will on FilledTile, then change the m_needToDoRecursion to true
	if (board[m_location.x / SIZE::TILE_SIZE][m_location.y / SIZE::TILE_SIZE]->isEmpty() &&
		(!board[nextLoc.x / SIZE::TILE_SIZE][nextLoc.y / SIZE::TILE_SIZE]->isEmpty())) // meet filled or trail
		m_needToDoRecursion = true;
	



	if (m_inTrailMode) 
	{
		board[row][col] = std::make_unique<TrailTile>(sf::Vector2f(row * SIZE::TILE_SIZE, col * SIZE::TILE_SIZE), m_SfmlMan);
	}


	if (m_needToDoRecursion)
	{
		int x = static_cast<int>(m_location.x / SIZE::TILE_SIZE);
		int y = static_cast<int>(m_location.y / SIZE::TILE_SIZE);
		FloodFillRec(board,x,y);
		updateSigns(board);
		//cleanSigns(board);
	}



	m_inTrailMode = false; // reset the mode after updating the location
	m_needToDoRecursion = false; // reset the need to do recursion after updating the location

}



