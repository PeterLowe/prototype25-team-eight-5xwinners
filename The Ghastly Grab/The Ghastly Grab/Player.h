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

	void movement(int t_facing, int t_room);	// function that redirects movement based on room
	void resetTexture();
	void reset(int t_room);		// resets character position when entering a new room

	sf::Vector2f getPosition();
	sf::Sprite getBody();
	sf::RectangleShape getLegs();

	void bounaryCheck(int t_facing, int t_room);
	void outsideBounds(int t_facing, sf::Vector2f& t_leg, sf::Vector2f& t_body);	// movement specific to outside
	void kitchenBounds(int t_facing, sf::Vector2f& t_leg, sf::Vector2f& t_body); // movement specific to kitchen


	void leftDiaBounds(sf::Vector2f& t_leg, sf::Vector2f& t_body, int t_facing);
	void rightDiaBounds(sf::Vector2f& t_leg, sf::Vector2f& t_body, int t_facing);






private:
	void moveSide();		// move player right or left
	void moveUp();			// function to move character up
	int m_frame = 0;		// frame for all animation

	sf::Texture m_texture; //texture for Player
	sf::Texture m_textureUp;	// texture for player moving down
	sf::Texture m_textureRight;	// texture for player moving right
	sf::Texture m_textureLeft;	// texture for player moving left
	sf::Sprite m_sprite; //sprite used to represent Player

	sf::RectangleShape m_legsRect{ {LEG_WIDTH, LEG_HEIGHT} };		// Box to hold legs

	const int m_speed = 5;
};