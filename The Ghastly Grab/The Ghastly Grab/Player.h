//author team_8 - [5xWinners]
#pragma once

#include "Globals.h" //include Global header file

#include "SFML/Graphics.hpp"
#include <iostream>

class Player
{
public:
	Player();
	void loadImage();

	void movement(int t_facing);

	void setPoosition(sf::Vector2f pos);

	sf::Vector2f getPosition();
	sf::Sprite getBody();

private:
	sf::Texture m_texture; //texture for Player
	sf::Sprite m_sprite; //sprite used to represent Player

	const int m_speed = 5;
};