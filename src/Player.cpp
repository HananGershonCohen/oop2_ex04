#include "Player.h"

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
	if (m_direction != newDirection)
	{
		m_direction = newDirection;
		ArrangeLocation(m_location);
	}

	m_location += newDirection * deltaTime * speed;
}

void Player::ArrangeLocation(sf::Vector2f loc)
{
	int newX = static_cast<int>(loc.x + SIZE::HalfPixelSize) / SIZE::TILE_SIZE;
	int newY = static_cast<int>(loc.y + SIZE::HalfPixelSize) / SIZE::TILE_SIZE;
	newX *= SIZE::TILE_SIZE;
	newY *= SIZE::TILE_SIZE;
	m_location =  sf::Vector2f{ static_cast<float>(newX), static_cast<float>(newY) };
}
//void Player::move(std::vector<std::unique_ptr<Tile>>& board, float deltaTime)
//{
//
//}



