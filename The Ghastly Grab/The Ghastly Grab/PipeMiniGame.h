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

	static const int MAX_FORKS = 19;	// Maximum number of forks (no. of t pipes in total)
	int fork[MAX_FORKS][10][10];		// Array saving information about all forks (1st is fork #, 2nd is x coord of T-Pipe where fork is, 3rd is y coord of T-Pipe)
	// 10 refers to maximum x and y coords (size of grid)
	// This is an extremely specific solution, but good enough I presume

	const float CELLSIZE = 64.0f;
	const int GRIDSIZE = 10;
	const int TPIPE[8] = { 51101, 51110, 50111, 51011, 61101, 61110, 60111, 61011 };	//all of the T pipes
	const int LPIPE[8] = { 51001, 51100, 50110, 50011, 61001, 61100, 60110, 60011 };	//all of the L pipes
	const int IPIPE[4] = { 51010, 50101, 61010, 60101 };								//I pipes
	const int DPIPE[8] = { 51000, 50100, 50010, 50001, 61000, 60100, 60010, 60001 };	//D pipes

	const int UP_CON[14] = { 51101, 51110, 51011, 61101, 61110, 61011, 51001, 51100, 61001, 61100, 51010, 61010, 51000, 61000 };			//all pipes with a connection going up
	const int RIGHT_CON[14] = { 51101, 51110, 50111, 61101, 61110, 60111, 51100, 50110, 61100, 60110, 50101, 60101, 50100, 60100 };			//connection going right
	const int DOWN_CON[14] = { 51110, 50111, 51011, 61110, 60111, 61011, 50110, 50011, 60110, 60011, 51010, 61010, 50010, 60010 };			//connection going down
	const int LEFT_CON[14] = { 51101, 50111, 51011, 61101, 60111, 61011, 51001, 50011, 61001, 60011, 50101, 60101, 50001, 60001 };			//connection going left

	//The last 4 digits of the 5 digit numbers represent each side of a tile in order of top, right, bottom, left.
	//1 represents a pipe on that side of the tile that can connect to the adjacent tile. 0 represents no pipe on that side.
	//For example, the number x1101 represents a T shaped pipe that connects to the top, right and left sides of the tile
	//The first digit of the number determines if the tile has access to water or not. 5 means no water and 6 means it has water. 
	//61999 is a special source tile that cannot rotate
	int m_grid[10][10] = {
		{ 50011, 51100, 50010, 51000, 51100, 51010, 50101, 51011, 51101, 50010 },
		{ 51010, 50110, 50110, 51010, 50110, 51100, 50000, 50010, 50110, 50010 },
		{ 50011, 50101, 51011, 50111, 51010, 51100, 50000, 51001, 50010, 50001 },
		{ 51000, 51100, 51110, 50111, 50101, 50001, 50000, 51011, 50111, 50111 },
		{ 50110, 50111, 50110, 51101, 50011, 51001, 50101, 51100, 51000, 51010 },
		{ 50000, 50000, 50001, 50101, 50110, 51100, 50100, 50000, 51001, 50111 },
		{ 50011, 50101, 51010, 50111, 50110, 50100, 51101, 50110, 51000, 51010 },
		{ 51000, 51001, 51010, 51010, 51101, 50100, 51110, 50011, 50000, 50101 },
		{ 51000, 50011, 51101, 51001, 61999, 51001, 51001, 51000, 50011, 51010 },
		{ 50011, 51010, 50110, 50100, 50100, 51011, 50101, 51010, 51101, 50011 }, };


public:

	Pipe();
	void setupSprites();
	void render(sf::RenderWindow& t_window);
	void update();
	void rotate(sf::Vector2f t_pos);
	void checkWater();
	void checkDirection(int t_posx, int t_posy, bool& t_up, bool& t_right, bool& t_down, bool& t_left);
	bool checkConnection();
	//void processMouse(sf::Event t_event);
	//void setClickPos(sf::Vector2f t_pos) { m_clickPos = t_pos; }
};