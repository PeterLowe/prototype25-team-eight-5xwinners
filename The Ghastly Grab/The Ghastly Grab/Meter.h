//author team_8 - [5xWinners]

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Globals.h"

class Meter
{
	sf::Texture m_texture;	// array of 10 textures for all 10 states
	std::string m_namesTexture[MAX_METERS];
	sf::Sprite m_sprite;				// sprite for it

	int m_filledAmount = 0;		// int to see how much filled

public:

	void setupSprite();
	int getFilled();
	void onClick();
	sf::Sprite getBody();

private:

	void update();
};