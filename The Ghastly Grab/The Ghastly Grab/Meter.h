//author team_8 - [5xWinners]

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Globals.h"
#include <SFML/Audio.hpp>

class Meter
{
	sf::Texture m_texture;	// array of 10 textures for all 10 states
	std::string m_namesTexture[MAX_METERS];
	sf::Sprite m_sprite;				// sprite for it

	int m_filledAmount = 0;		// int to see how much filled

	sf::Sound m_spook;	// Spooky sound fx
	sf::SoundBuffer m_door;
	sf::SoundBuffer m_knock;
	sf::SoundBuffer m_coin;
	sf::SoundBuffer m_foot;
	sf::SoundBuffer m_wind;
	sf::SoundBuffer m_racket;
	sf::SoundBuffer m_metal;

public:

	void setupSprite();
	void loadMusic();
	int getFilled();
	void onClick();
	sf::Sprite getBody();

private:

	void update();
};