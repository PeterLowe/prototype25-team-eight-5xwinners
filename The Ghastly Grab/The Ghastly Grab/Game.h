//author team_8 - [5xWinners]

#ifndef GAME_HPP
#define GAME_HPP

//include guards used so we don't process this file twice
//same as #pragma once
//Don't forget the endif at the bottom

#include "Player.h" //include Player header file
#include "Globals.h" //include Global header file
#include "Riches.h"
#include "Menus.h"
#include "Meter.h"
#include "Hud.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>




class Game
{
	Player m_player;

public:
	Game();
	~Game();
	//main method for game

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processMouse(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void renderScreens();
	void checkClick();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

	bool bounaryCheck();

	void setUp();
	void setupAudio();

	Menus Menus;

	sf::Music m_bgMusic;	// BG Music	

	sf::Vector2f m_mousePressed;

	Riches m_riches[MAX_RICHES];

	Meter m_meter;

	Hud Hud;

	int m_screen = MAIN;

};

#endif //!GAME_HPP

