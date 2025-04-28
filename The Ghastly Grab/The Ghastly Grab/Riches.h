//author team_8 - [5xWinners]

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"
#include <SFML/Audio.hpp>

class Riches
{
	sf::Texture m_richesTexture;
	sf::Sprite m_richesSprite;

	bool m_isFound = false;

	sf::Sound m_sfx;
	sf::SoundBuffer m_sfxBuffer;

public:
	
	void setupSprite(int t_index);
	void onClick();
	bool getClicked();
	sf::Sprite getBody();
};