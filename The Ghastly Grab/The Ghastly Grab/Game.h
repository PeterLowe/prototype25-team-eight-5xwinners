//author team_8 - [5xWinners]

#ifndef GAME_HPP
#define GAME_HPP

//include guards used so we don't process this file twice
//same as #pragma once
//Don't forget the endif at the bottom

#include "Globals.h" //include Global header file

#include "Player.h" //include Player header file
#include "Covers.h"
#include "Riches.h"
#include "Tools.h"
#include "Rooms.h"
#include "Menus.h"
#include "Meter.h"
#include "Inventory.h" //include Inventory header file
#include "Hud.h"
#include "PipeMiniGame.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game
{
public:
	Game();
	~Game();
	//main method for game

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processMouse(sf::Event t_event);
	void gamePlayClick();
	void inventoryClick();

	void update(sf::Time t_deltaTime);
	void render();
	void renderScreens();
	void screenSwitchButtons();
	void renderInventory();
	void screenSwitchKeys();

	void setUp();
	void setupAudio();

	void miniGame();

	sf::RenderWindow m_window; // main SFML window
	sf::RenderWindow m_window2; 

	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

	bool bounaryCheck();

	Menus Menus;
	Hud Hud;
	Inventory m_inventory;

	Player m_player;
	Rooms m_rooms[MAX_ROOMS];

	Riches m_riches[MAX_RICHES];
	Tools m_tools[MAX_TOOLS];
	Covers m_covers[MAX_COVERS];

	Meter m_meter;

	Pipe m_pipe;

	int m_screen = MAIN;
	sf::Music m_bgMusic;	// BG Music	
	sf::Vector2f m_mousePressed;
};

#endif //!GAME_HPP

