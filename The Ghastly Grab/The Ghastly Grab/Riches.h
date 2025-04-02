//author team_8 - [5xWinners]

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"

class Riches
{
	sf::Texture p_texture;		// placeholder texture
	sf::Sprite p_sprite;

	bool m_isFound = false;

public:
	
	void setupSprite();
	void onClick();
	bool getClicked();
	sf::Sprite getBody();
};