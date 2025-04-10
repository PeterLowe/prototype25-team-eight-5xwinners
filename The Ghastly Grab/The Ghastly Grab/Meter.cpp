//author team_8 - [5xWinners]

#include "Meter.h"

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Meter::setupSprite()
{
	if (!m_texture.loadFromFile("ASSETS/IMAGES/METER.png"))
	{
		std::cout << "error with player image file";
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect{ 0,0,640,80 });
	m_sprite.setPosition(80.0f, 722.50f);

}

void Meter::update()
{
	for (int i = 0; i < MAX_METERS; i++)
	{
		if (m_filledAmount == i)
		{
			m_sprite.setTextureRect(sf::IntRect{ 0,i*80,640, 80 });
			break;
		}
	}

}

void Meter::onClick()
{
	int mainChance = rand() % 3;
	int jumpScare;

	if (mainChance == SCARE)
	{
		m_filledAmount++;
	}

	if (m_filledAmount == 5)
	{
		jumpScare = rand() % 5;
		if (jumpScare == SCARE)
		{
			m_filledAmount = 10;
		}
	}
	else if (m_filledAmount == 6)
	{
		jumpScare = rand() % 4;
		if (jumpScare == SCARE)
		{
			m_filledAmount = 10;
		}
	}
	else if (m_filledAmount == 7)
	{
		jumpScare = rand() % 3;
		if (jumpScare == SCARE)
		{
			m_filledAmount = 10;
		}
	}
	else if (m_filledAmount == 8)
	{
		jumpScare = rand() % 2;
		if (jumpScare == SCARE)
		{
			m_filledAmount = 10;
		}
	}
	else if (m_filledAmount == 9)
	{
		m_filledAmount = 10;
	}

	update();

}

sf::Sprite Meter::getBody()
{
	return m_sprite;
}

int Meter::getFilled()
{
	return m_filledAmount;
}