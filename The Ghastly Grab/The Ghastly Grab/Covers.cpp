#include "Covers.h"


void Covers::setupSprite(int t_num)
{
	switch (t_num)
	{
	case 0:
		
		if (!m_finalTexture.loadFromFile("ASSETS\\IMAGES\\matup.png"))
		{
			std::cout << "Problem loading matup image." << std::endl;
		}

		if (!m_initialTexture.loadFromFile("ASSETS\\IMAGES\\matdown.png"))
		{
			std::cout << "Problem loading matdown image." << std::endl;
		}

		if (!m_matFlap.loadFromFile("ASSETS\\AUDIO\\carpet.ogg"))
		{
			std::cout << "carpet Flap no load"; // error message
		}

		m_sprite.setTexture(m_initialTexture);
		m_sprite.setPosition(370, 339);
		m_sprite.setScale(0.5, 0.5);
		break;

	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}

}

sf::Sprite Covers::getBody()
{
	return m_sprite;
}

void Covers::onClick(int t_num)
{
	m_isFound = true;
	switch (t_num)
	{
	case 0:
		m_sprite.setTexture(m_finalTexture);
		m_sfx.setBuffer(m_matFlap);
		m_sfx.play();
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}
}

bool Covers::getClicked()
{
	return m_isFound;
}