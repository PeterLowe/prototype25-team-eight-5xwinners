//author team_8 - [5xWinners]

#include "Riches.h"

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Riches::setupSprite(int t_index)
{
	if (!m_richesTexture.loadFromFile("ASSETS\\IMAGES\\UNUSABLE_ITEMS.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading unusable items texture" << std::endl;
	}
	m_richesSprite.setTexture(m_richesTexture);


	sf::IntRect richesTextureRect;
	switch (t_index)
	{
	case 0:
		richesTextureRect = { 0, 0, 54, 66 };
		break;
	case 1:
		richesTextureRect = { 0, 68, 64, 60 };
		break;
	case 2:
		richesTextureRect = { 0, 132, 65, 60 };
		break;
	case 3:
		richesTextureRect = { 0, 194, 54, 66 };
		break;
	case 4:
		richesTextureRect = { 0, 260 , 64 , 60 };
		break;
	case 5:
		richesTextureRect = { 0 , 320, 70, 64 };
		break;
	case 6:
		richesTextureRect = { 0 , 386, 64, 90 };
		break;
	case 7:
		richesTextureRect = { 0 , 480, 64, 30 };
		break;
	case 8:
		richesTextureRect = { 0, 510, 96, 32 };
		break;
	}
		
	m_richesSprite.setTextureRect(richesTextureRect);

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