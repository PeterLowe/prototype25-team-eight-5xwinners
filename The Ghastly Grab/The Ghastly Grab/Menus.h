#pragma once

#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"
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

	// Temporary for readability
	void mainMenuText();
	sf::Text getGameTitle();
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

	// Clicking Buttons
	int clickMenu(sf::Vector2f t_clickPos);

private:

	const int BUT_WIDTH = 192; // Button width
	const int BUT_HEIGHT = 64; // Button height

	// MainMenu
	sf::Texture m_menuBack; // Background graphic with game title

	// Temporary for readability
	sf::Font m_ArialBlackfont;
	sf::Text m_gameTitle;
	sf::Text m_play;
	sf::Text m_sound;
	sf::Text m_help;
	sf::Text m_credits;
	sf::FloatRect m_titleSize;
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
	sf::Vector2f m_titlePos{ SCREEN_WIDTH / 2,150.0f }; // Game title position
	sf::Vector2f m_playPos{ SCREEN_WIDTH / 2,300.0f }; // Play button position
	sf::Vector2f m_soundPos{ SCREEN_WIDTH / 2,382.0f }; // Sound Button Position
	sf::Vector2f m_helpPos{ SCREEN_WIDTH / 2,464.0f }; // Help button position
	sf::Vector2f m_creditsPos{ SCREEN_WIDTH / 2,546.0f }; // Credits button position

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
};