#pragma once

#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include "Globals.h"

class Menus
{
public:

	Menus();

	// Main Menu
	void mainMenuShapes();
	sf::RectangleShape getMainPlay();
	sf::RectangleShape getMainSound();
	sf::RectangleShape getMainHelp();
	sf::RectangleShape getMainCredits();

	sf::Texture m_mainText;
	sf::Sprite m_mainSprite;

	void loadMenu();
	sf::Sprite getMain();
	void animateMainMenu();

	// Game Over Screen
	sf::Texture m_scareText;
	sf::Sprite m_scareSprite;

	void loadScare();
	sf::Sprite getScare();
	void animateScare();

	// Temporary for readability
	void mainMenuText();
	sf::Text getPlayText();
	sf::Text getSoundText();
	sf::Text getHelpText();
	sf::Text getCreditsText();
	//

	// Help Menu
	void helpMenuShapes();
	sf::RectangleShape getHelpReturn();
	sf::RectangleShape getHelpInfo();
	sf::Text getReturnText();

	// Gameplay
	void gameplayScreen();
	sf::RectangleShape getItemList();
	sf::RectangleShape getBagIcon();

	// Inventory
	void inventoryScreen();
	sf::RectangleShape getInvReturn();
	sf::Text getInvReturnText();

private:

	const int BUT_WIDTH = 192; // Button width
	const int BUT_HEIGHT = 64; // Button height

	// MainMenu
	sf::Texture m_menuBack; // Background graphic with game title

	// Temporary for readability
	sf::Font m_ArialBlackfont;
	sf::Text m_play;
	sf::Text m_sound;
	sf::Text m_help;
	sf::Text m_credits;
	sf::FloatRect m_playSize;
	sf::FloatRect m_soundSize;
	sf::FloatRect m_helpSize;
	sf::FloatRect m_creditSize;
	//

	// Main Menu
	sf::RectangleShape m_playDef; // Default button shape
	sf::RectangleShape m_soundDef; // Default button shape
	sf::RectangleShape m_helpDef; // Default button shape
	sf::RectangleShape m_creditsDef; // Default button shape
	sf::Vector2f m_playPos{ SCREEN_WIDTH / 2,450.0f }; // Play button position
	sf::Vector2f m_soundPos{ SCREEN_WIDTH / 2,532.0f }; // Sound Button Position
	sf::Vector2f m_helpPos{ SCREEN_WIDTH / 2,614.0f }; // Help button position
	sf::Vector2f m_creditsPos{ SCREEN_WIDTH / 2,696.0f }; // Credits button position

	// Help Screen
	sf::RectangleShape m_helpReturn;
	sf::RectangleShape m_helpInfo;
	sf::Text m_return;
	sf::FloatRect m_returnSize;

	// Gameplay Screen
	sf::RectangleShape m_itemList;
	sf::RectangleShape m_bagIcon;

	// Inventory Screen
	sf::RectangleShape m_invReturnShape;
	sf::Text m_invReturnText;
	sf::FloatRect m_invReturnSize;

	int m_totalFrame = 8;
	int m_scareFrames = 5;
	int m_scareRow = 0;
	float m_frameCounter = 0.0f;
	float m_frameIncrement = 0.1f;
};