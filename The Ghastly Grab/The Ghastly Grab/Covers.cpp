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

		if (!m_cupboardCloseText.loadFromFile("ASSETS//IMAGES//cupboardClosed.png"))
		{
			std::cout << "Problem loading closed cupboard image" << std::endl;
		}

		if (!m_cupboardOpenText.loadFromFile("ASSETS//IMAGES//cupboardOpen.png"))
		{
			std::cout << "Problem loading open cupboard image" << std::endl;
		}

		if (!m_cupboard.loadFromFile("ASSETS\\AUDIO\\cupboard.ogg"))
		{
			std::cout << "cupboard sound no load"; // error message
		}

		if (!m_safeText.loadFromFile("ASSETS//IMAGES//safe.png"))
		{
			std::cout << "Problem loading safe image" << std::endl;
		}

		m_cupboardSprite.setTexture(m_cupboardCloseText);
		m_cupboardSprite.setPosition(184, 0);

		m_safeSprite.setTexture(m_safeText);
		m_safeSprite.setPosition(230, 60);

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
		m_cupboardSprite.setTexture(m_cupboardOpenText);
		m_sfx.setBuffer(m_cupboard);
		m_sfx.play();
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

sf::Sprite Covers::getCupboard()
{
	return m_cupboardSprite;
}

sf::Sprite Covers::getSafe()
{
	return m_safeSprite;
}
