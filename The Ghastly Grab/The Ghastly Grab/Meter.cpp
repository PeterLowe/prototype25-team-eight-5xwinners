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

	loadMusic();
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
		int spook = rand() % 7;
		switch (spook)
		{
		case 0:
			m_spook.setBuffer(m_door);
			break;
		case 1:
			m_spook.setBuffer(m_knock);
			break;
		case 2:
			m_spook.setBuffer(m_racket);
			break;
		case 3:
			m_spook.setBuffer(m_wind);
			break;
		case 4:
			m_spook.setBuffer(m_coin);
			break;
		case 5:
			m_spook.setBuffer(m_foot);
			break;
		case 6:
			m_spook.setBuffer(m_metal);
			break;
		}
		m_spook.play();
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

void Meter::loadMusic()
{
	if (!m_door.loadFromFile("ASSETS\\AUDIO\\dor.ogg"))
	{
		std::cout << "door spook no load"; // error
	}

	if (!m_knock.loadFromFile("ASSETS\\AUDIO\\knock.ogg"))
	{
		std::cout << "knock spook no load"; // error
	}

	if (!m_racket.loadFromFile("ASSETS\\AUDIO\\racket.ogg"))
	{
		std::cout << "racket spook no load"; // error
	}

	if (!m_wind.loadFromFile("ASSETS\\AUDIO\\wind.ogg"))
	{
		std::cout << "wind spook no load"; // error
	}

	if (!m_coin.loadFromFile("ASSETS\\AUDIO\\coin.ogg"))
	{
		std::cout << "coin spook no load"; // error
	}

	if (!m_foot.loadFromFile("ASSETS\\AUDIO\\foot.ogg"))
	{
		std::cout << "footsteps spook no load"; // error
	}
 
	if (!m_metal.loadFromFile("ASSETS\\AUDIO\\metal.ogg"))
	{
		std::cout << "metal spook music no load"; // error
	}
}