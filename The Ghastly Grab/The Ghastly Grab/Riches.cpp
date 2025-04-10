//author team_8 - [5xWinners]

#include "Riches.h"

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Riches::setupSprite(sf::IntRect t_textureRect)
{
	if (!m_richesTexture.loadFromFile("ASSETS\\IMAGES\\UNUSABLE_ITEMS.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading placeholder texture" << std::endl;
	}
	m_richesSprite.setTexture(m_richesTexture);
	m_richesSprite.setTextureRect(t_textureRect);
	m_richesSprite.setPosition(rand()%601+200, rand()%151+200);


}

void Riches::onClick()
{
	m_isFound = true;
}

sf::Sprite Riches::getBody()
{
	return m_richesSprite;
}

bool Riches::getClicked()
{
	return m_isFound;
}