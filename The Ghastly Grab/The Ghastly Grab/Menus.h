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

	void MainMenu();
	sf::Text getGameTitle();
	sf::RectangleShape getMainPlay();
	sf::RectangleShape getMainSound();
	sf::RectangleShape getMainHelp();
	sf::RectangleShape getMainCredits();

private:

	std::string m_currentScreen = "MainMenu";

	// MainMenu
	sf::Texture m_menuBack; // Background graphic with game title

	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_gameTitle; // text used for message on screen

	sf::RectangleShape m_playDef; // Default button shape
	sf::RectangleShape m_soundDef; // Default button shape
	sf::RectangleShape m_helpDef; // Default button shape
	sf::RectangleShape m_creditsDef; // Default button shape

	sf::Vector2f m_titlePos{ 175.0f,100.0f }; // Game title position
	sf::Vector2f m_playPos{ 400.0f,250.0f }; // Play button position
	sf::Vector2f m_soundPos{ 400.0f,332.0f }; // Sound Button Position
	sf::Vector2f m_helpPos{ 400.0f,414.0f }; // Help button position
	sf::Vector2f m_creditsPos{ 400.0f,496.0f }; // Credits button position

	const int BUT_WIDTH = 192; // Button width
	const int BUT_HEIGHT = 64; // Button height

};