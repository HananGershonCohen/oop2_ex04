#include "Enemy.h"

Enemy::Enemy(sf::Vector2f location, SfmlManager& SfmlMan) : MobileObject(location, sf::Sprite{ SfmlMan.getEnemyTex() })
{
}

void Enemy::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location);
	window.draw(m_sprite);
}

void Enemy::move(std::vector<std::vector<std::unique_ptr<Tile>>>& board, float deltaTime)
{

}
