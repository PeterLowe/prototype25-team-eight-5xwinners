#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"

class Tools
{
	sf::Texture m_toolsTexture;
	sf::Sprite m_toolsSprite;

	bool m_isFound = false;

public:

	void setupSprite(int t_num);
	sf::Sprite getBody();
	void onClick();
	bool getClicked();
};