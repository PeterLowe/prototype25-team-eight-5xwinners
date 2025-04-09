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

	sf::Vector2f getPosition();
	sf::Sprite getBody();

	void bounaryCheck(int t_facing);
	void leftDiaBounds(sf::Vector2f& t_leg, sf::Vector2f& t_body, int t_facing);
	void rightDiaBounds(sf::Vector2f& t_leg, sf::Vector2f& t_body, int t_facing);
	sf::RectangleShape m_legsRect{ {LEG_WIDTH, LEG_HEIGHT} };		// Box to hold legs

private:
	sf::Texture m_texture; //texture for Player
	sf::Sprite m_sprite; //sprite used to represent Player

	const int m_speed = 5;
};