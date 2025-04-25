#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"
#include <SFML/Audio.hpp>

class Covers
{
	sf::Texture m_initialTexture;
	sf::Texture m_finalTexture;
	sf::Sprite m_sprite;

	sf::Sound m_sfx;

	sf::SoundBuffer m_matFlap;

	bool m_isFound = false;

public:

	void setupSprite(int t_num);
	sf::Sprite getBody();
	void onClick(int t_num);
	bool getClicked();
};