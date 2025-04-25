#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"
#include <SFML/Audio.hpp>

class Tools
{
	sf::Texture m_toolsTexture;
	sf::Sprite m_toolsSprite;
	sf::Sound m_sfx;

	sf::SoundBuffer m_keyJangle;

	bool m_isFound = false;

public:

	void setupSprite(int t_num);
	sf::Sprite getBody();
	void onClick(int t_num);
	bool getClicked();
};