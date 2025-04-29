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

	if (!m_sfxBuffer.loadFromFile("ASSETS\\AUDIO\\riches.ogg"))
	{
		std::cout << "riches sfx no load"; // error message
	}
	m_sfx.setBuffer(m_sfxBuffer);
	m_richesSprite.setTexture(m_richesTexture);


	sf::IntRect richesTextureRect;
	switch (t_index)
	{
	case 0:
		richesTextureRect = { 0, 0, 54, 66 };
		m_richesSprite.setPosition(760, 250);
		m_richesSprite.setScale(0.4, 0.4);
		break;
	case 1:
		richesTextureRect = { 0, 68, 64, 60 };
		m_richesSprite.setPosition(110, 310);
		m_richesSprite.setScale(0.9, 0.9);
		break;
	case 2:
		richesTextureRect = { 0, 132, 65, 60 };
		m_richesSprite.setPosition(830, 230);
		m_richesSprite.setScale(0.5, 0.5);
		break;
	case 3:
		richesTextureRect = { 0, 194, 54, 66 };
		m_richesSprite.setPosition(650, 220);
		m_richesSprite.setScale(0.8, 0.8);
		break;
	case 4:
		richesTextureRect = { 0, 260 , 64 , 60 };
		m_richesSprite.setPosition(120, 200);
		break;
	case 5:
		richesTextureRect = { 0 , 320, 70, 64 };
		m_richesSprite.setPosition(290, 290);
		break;
	case 6:
		richesTextureRect = { 0 , 386, 64, 90 };
		m_richesSprite.setPosition(766, 108);
		m_richesSprite.setScale(1.2, 1.7);
		break;
	case 7:
		richesTextureRect = { 0 , 480, 64, 30 };
		m_richesSprite.setPosition(835, 225);
		break;
	case 8:
		richesTextureRect = { 0, 510, 96, 32 };
		m_richesSprite.setPosition(550, 50);
		m_richesSprite.setScale(2, 1);
		break;
	}
		
	m_richesSprite.setTextureRect(richesTextureRect);

}

void Riches::onClick()
{
	m_isFound = true;
	m_sfx.play();
}

sf::Sprite Riches::getBody()
{
	return m_richesSprite;
}

bool Riches::getClicked()
{
	return m_isFound;
}