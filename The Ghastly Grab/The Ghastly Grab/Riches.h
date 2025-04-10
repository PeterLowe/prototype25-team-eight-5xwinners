//author team_8 - [5xWinners]

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"

class Riches
{
	sf::Texture m_richesTexture;
	sf::Sprite m_richesSprite;

	bool m_isFound = false;

public:
	
	void setupSprite(sf::IntRect t_textureRect);
	void onClick();
	bool getClicked();
	sf::Sprite getBody();
};