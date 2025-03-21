//author team_8 - [5xWinners]

#include "Player.h"

Player::Player()
{
	loadImage();
}

void Player::loadImage()
//loads player sprite from files
{
	if (!m_texture.loadFromFile("ASSETS/IMAGES/PLAYER.png"))
	{
		std::cout << "error with player image file";
	}

	m_sprite.setTexture(m_texture);
}

void Player::movement(int t_facing)
//moves the player
{
	sf::Vector2f pos(m_sprite.getPosition());

	if (t_facing == LEFT)
	{
		pos.x = pos.x - m_speed;
	}
	if (t_facing == RIGHT)
	{
		pos.x = pos.x + m_speed;
	}
	if (t_facing == UP)
	{
		pos.y = pos.y - m_speed;
	}
	if (t_facing == DOWN)
	{
		pos.y = pos.y + m_speed;
	}

	m_sprite.setPosition(pos);
}

void Player::setPoosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}

sf::Vector2f Player::getPosition()
{
	return m_sprite.getPosition();
}

sf::Sprite Player::getBody()
{
	return m_sprite;
}