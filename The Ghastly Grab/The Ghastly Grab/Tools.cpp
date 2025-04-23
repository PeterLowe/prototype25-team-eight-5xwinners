#include "Tools.h"


void Tools::setupSprite(int t_num)
{
	if (!m_toolsTexture.loadFromFile("ASSETS\\IMAGES\\USABLE_ITEMS.png"))
	{
		std::cout << "Problem loading tools image." << std::endl;
	}

	m_toolsSprite.setTexture(m_toolsTexture);

	switch (t_num)
	{
		case 1:
			m_toolsSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
			m_toolsSprite.setPosition(480, 337);
			break;
		case 2:
			m_toolsSprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
			m_toolsSprite.setPosition(200, 200);
			break;
		case 3:
			m_toolsSprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
			m_toolsSprite.setPosition(300, 300);
			break;
		case 4:
			m_toolsSprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
			m_toolsSprite.setPosition(200, 400);
			break;
	}

}

sf::Sprite Tools::getBody()
{
	return m_toolsSprite;
}

void Tools::onClick()
{
	m_isFound = true;
	m_toolsSprite.setColor(sf::Color::Transparent);
}

bool Tools::getClicked()
{
	return m_isFound;
}