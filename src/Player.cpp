#include "Player.h"

Player::Player(sf::Vector2f location, SfmlManager& SfmlMan) : MobileObject(location, sf::Sprite{ SfmlMan.getTilesTex() })
{
}

void Player::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location);
	m_sprite.setTextureRect(sf::IntRect(SIZE::TILE_SIZE * 1, 0, SIZE::TILE_SIZE, SIZE::TILE_SIZE));
	window.draw(m_sprite);
}

void Player::move(float deltaTime)
{
	// Handle player movement here
	// Example: m_location += speed * deltaTime;
	
	sf::Vector2f direction{ 0,0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction.y -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction.y += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction.x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction.x += 1;
	}

	float speed = 100;
	// m_sprite.move(direction * deltaTime * speed);
	 m_location += direction * deltaTime * speed; 


}

//void Player::move(std::vector<std::unique_ptr<Tile>>& board, float deltaTime)
//{
//
//}
