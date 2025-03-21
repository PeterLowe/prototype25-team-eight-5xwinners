#pragma once

#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"

class Menus
{
public:

	Menus();

	void chooseScreen(int t_screen);
	std::string currentScreen();

	void mainMenuShapes();

	// Temporary for readability
	void mainMenuText();

	sf::Text getGameTitle();
	sf::Text getPlayText();
	sf::Text getSoundText();
	sf::Text getHelpText();
	sf::Text getCreditsText();
	//

	sf::RectangleShape getMainPlay();
	sf::RectangleShape getMainSound();
	sf::RectangleShape getMainHelp();
	sf::RectangleShape getMainCredits();

	void helpMenuShapes();

	sf::RectangleShape getHelpReturn();
	sf::RectangleShape getHelpInfo();
	sf::Text getReturnText();

private:

	std::string m_currentScreen = "";

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

	sf::RectangleShape m_playDef; // Default button shape
	sf::RectangleShape m_soundDef; // Default button shape
	sf::RectangleShape m_helpDef; // Default button shape
	sf::RectangleShape m_creditsDef; // Default button shape

	sf::Vector2f m_titlePos{ 400.0f,100.0f }; // Game title position
	sf::Vector2f m_playPos{ 400.0f,250.0f }; // Play button position
	sf::Vector2f m_soundPos{ 400.0f,332.0f }; // Sound Button Position
	sf::Vector2f m_helpPos{ 400.0f,414.0f }; // Help button position
	sf::Vector2f m_creditsPos{ 400.0f,496.0f }; // Credits button position

	const int BUT_WIDTH = 192; // Button width
	const int BUT_HEIGHT = 64; // Button height

	sf::RectangleShape m_helpReturn;
	sf::RectangleShape m_helpInfo;

	sf::Text m_return;
	sf::FloatRect m_returnSize;

};