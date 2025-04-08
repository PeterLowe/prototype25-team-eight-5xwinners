#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Pipe
{
	sf::Texture m_pipeT_Texture;
	sf::Texture m_pipeL_Texture;
	sf::Texture m_pipeI_Texture;
	sf::Texture m_pipeD_Texture;
	sf::Texture m_pipeS_Texture;
	sf::Texture m_tile_Texture;
	sf::Sprite m_pipeT;
	sf::Sprite m_pipeL;
	sf::Sprite m_pipeI;
	sf::Sprite m_pipeD;
	sf::Sprite m_pipeS;
	sf::Sprite m_tile;
	sf::RectangleShape m_player;

	const int CELLSIZE = 64;

	//The 4 digit numbers represent each side of a tile in order of top, right, bottom, left. For example,
	//the number 1101 represents a tile with a T shaped pipe that connects to the top, right and left sides of the tile
	//1999 is a special source tile that cannot rotate
	int m_grid[10][10] = {
		{ 0110, 1100, 0010, 1000, 1100, 1010, 0101, 1011, 1101, 0010 },
		{ 1010, 0110, 0110, 1010, 0110, 1100, 0000, 0010, 0110, 0010 },
		{ 0011, 0101, 1011, 0111, 1010, 1100, 0000, 1001, 0010, 0001 },
		{ 1000, 1100, 1110, 0111, 0101, 0001, 0000, 1011, 0111, 0111 },
		{ 0110, 0111, 0110, 1101, 0011, 1001, 0101, 1100, 1000, 1010 },
		{ 0000, 0000, 0001, 0101, 0110, 1100, 0100, 0000, 1001, 0111 },
		{ 0011, 0101, 1010, 0111, 0110, 0100, 1101, 0110, 1000, 1010 },
		{ 1000, 1001, 1010, 1010, 1101, 0100, 1110, 0011, 0000, 0101 },
		{ 1000, 0011, 1101, 1001, 1999, 1001, 1001, 1000, 0011, 1010 },
		{ 0011, 1010, 0110, 0100, 0100, 1011, 0101, 1010, 1101, 0011 }, };


public:

	Pipe();
	void setupSprites();
	void render(sf::RenderWindow& t_window);
};