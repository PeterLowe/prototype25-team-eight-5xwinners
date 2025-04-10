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

	sf::Vector2f m_clickPos;

	const float CELLSIZE = 64.0f;
	const int GRIDSIZE = 10;

	//The 4 digit numbers represent each side of a tile in order of top, right, bottom, left. For example,
	//the number 1101 represents a tile with a T shaped pipe that connects to the top, right and left sides of the tile
	//1999 is a special source tile that cannot rotate
	int m_grid[10][10] = {
		{ 50011, 51100, 50010, 51000, 51100, 51010, 50101, 51011, 51101, 50010 },
		{ 51010, 50110, 50110, 51010, 50110, 51100, 50000, 50010, 50110, 50010 },
		{ 50011, 50101, 51011, 50111, 51010, 51100, 50000, 51001, 50010, 50001 },
		{ 51000, 51100, 51110, 50111, 50101, 50001, 50000, 51011, 50111, 50111 },
		{ 50110, 50111, 50110, 51101, 50011, 51001, 50101, 51100, 51000, 51010 },
		{ 50000, 50000, 50001, 50101, 50110, 51100, 50100, 50000, 51001, 50111 },
		{ 50011, 50101, 51010, 50111, 50110, 50100, 51101, 50110, 51000, 51010 },
		{ 51000, 51001, 51010, 51010, 51101, 50100, 51110, 50011, 50000, 50101 },
		{ 51000, 50011, 51101, 51001, 51999, 51001, 51001, 51000, 50011, 51010 },
		{ 50011, 51010, 50110, 50100, 50100, 51011, 50101, 51010, 51101, 50011 }, };


public:

	Pipe();
	void setupSprites();
	void render(sf::RenderWindow& t_window);
	void update();
	void rotate(sf::Vector2f t_pos);
	void dothing();
	//void processMouse(sf::Event t_event);
	//void setClickPos(sf::Vector2f t_pos) { m_clickPos = t_pos; }
};