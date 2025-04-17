//author team_8 - [5xWinners]

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"

class Rooms
{

public:
	Rooms();
	
	void loadBackgrounds();

	sf::Sprite getBackground();

	void roomChange(int t_room);

private:

	sf::Texture m_outsideTexture;
	sf::Texture m_hallwayLeftTexture;
	sf::Texture m_hallwayRightTexture;
	sf::Texture m_greenHouseTexture;
	sf::Texture m_kitchenTexture;
	sf::Texture m_livingTexture;
	sf::Texture m_bedroomLeftTexture;
	sf::Texture m_bedroomRightTexture;
	sf::Texture m_bathroomTexture;

	sf::Sprite m_background;




};