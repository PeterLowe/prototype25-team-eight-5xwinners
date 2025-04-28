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

	sf::Texture m_cupboardCloseText;
	sf::Texture m_cupboardOpenText;
	sf::Texture m_safeText;

	sf::Sprite m_cupboardSprite;
	sf::Sprite m_safeSprite;

	sf::Sound m_sfx;

	sf::SoundBuffer m_matFlap;
	sf::SoundBuffer m_cupboard;

	bool m_isFound = false;

public:

	void setupSprite(int t_num);
	sf::Sprite getBody();
	void onClick(int t_num);
	bool getClicked();


	sf::Sprite getCupboard();
	sf::Sprite getSafe();
};