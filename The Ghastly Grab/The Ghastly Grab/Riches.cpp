//author team_8 - [5xWinners]

#include "Riches.h"
#include <iostream>


/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Riches::setupSprite()
{
	if (!p_texture.loadFromFile("ASSETS\\IMAGES\\placeholder.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading placeholder texture" << std::endl;
	}
	p_sprite.setTexture(p_texture);
	p_sprite.setPosition(300.0f, 180.0f);
}


void Riches::onClick()
{
	m_isFound = true;
}

sf::Sprite Riches::getBody()
{
	return p_sprite;
}

bool Riches::getClicked()
{
	return m_isFound;
}
