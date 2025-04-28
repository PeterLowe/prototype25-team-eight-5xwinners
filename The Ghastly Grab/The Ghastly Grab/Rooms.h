//author team_8 - [5xWinners]

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"
#include <SFML/Audio.hpp>

class Rooms
{

public:
	Rooms();
	
	void loadBackgrounds();
	void loadMusic();

	sf::Sprite getBackground();

	void roomChange(int t_room);

private:

	sf::Texture m_outsideTexture;
	sf::Texture m_outsideNoDoorTexture;
	sf::Texture m_hallwayLeftTexture;
	sf::Texture m_hallwayRightTexture;
	sf::Texture m_greenHouseTexture;
	sf::Texture m_kitchenTexture;
	sf::Texture m_livingTexture;
	sf::Texture m_bedroomLeftTexture;
	sf::Texture m_bedroomRightTexture;
	sf::Texture m_bathroomTexture;

	sf::Sprite m_background;

	sf::Sound m_bgMusic;
	sf::SoundBuffer m_outsideMusic;
	sf::SoundBuffer m_hallMusic;
	sf::SoundBuffer m_livingMusic;
	sf::SoundBuffer m_bathMusic;
	sf::SoundBuffer m_kitchenMusic;
	sf::SoundBuffer m_bedMusic;

	sf::Sound m_door;
	sf::SoundBuffer m_doorOneBuffer;
	sf::SoundBuffer m_doorTwoBuffer;
};