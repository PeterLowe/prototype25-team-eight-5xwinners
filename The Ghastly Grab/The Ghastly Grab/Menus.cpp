#include "Menus.h"

// Written by Daemon
Menus::Menus() // Default constructor
{
	MainMenu();
}

/// <summary>
///  This function toggles between active screens based on integer value.
/// </summary>
void Menus::chooseScreen(int t_screen)
{
	switch (t_screen)
	{
	case 1:
		m_currentScreen = "MainMenu";
		break;
	case 2:
		m_currentScreen = "SoundSettings";
		break;
	case 3:
		m_currentScreen = "Credits";
		break;
	case 4:
		m_currentScreen = "Info";
		break;
	}
}

/// <summary>
/// Returns current screen name as a string.
/// </summary>
std::string Menus::currentScreen()
{
	return m_currentScreen;
}

/// <summary>
/// Sets up graphics and bounding boxs for buttons
/// </summary>
void Menus::MainMenu()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "Issue loading menu font" << std::endl;
	}

	m_gameTitle.setFont(m_ArialBlackfont);
	m_gameTitle.setCharacterSize(64);
	m_gameTitle.setFillColor(sf::Color::Black);
	m_gameTitle.setString("Ghastly Grab");
	m_gameTitle.setPosition(m_titlePos);

	m_playDef.setFillColor(sf::Color::Blue);
	m_playDef.setSize(sf::Vector2f(BUT_WIDTH, BUT_HEIGHT));
	m_playDef.setOrigin(BUT_WIDTH / 2, BUT_HEIGHT / 2);
	m_playDef.setPosition(m_playPos);

	m_soundDef.setFillColor(sf::Color::Blue);
	m_soundDef.setSize(sf::Vector2f(BUT_WIDTH, BUT_HEIGHT));
	m_soundDef.setOrigin(BUT_WIDTH / 2, BUT_HEIGHT / 2);
	m_soundDef.setPosition(m_soundPos);

	m_helpDef.setFillColor(sf::Color::Blue);
	m_helpDef.setSize(sf::Vector2f(BUT_WIDTH, BUT_HEIGHT));
	m_helpDef.setOrigin(BUT_WIDTH / 2, BUT_HEIGHT / 2);
	m_helpDef.setPosition(m_helpPos);
	
	m_creditsDef.setFillColor(sf::Color::Blue);
	m_creditsDef.setSize(sf::Vector2f(BUT_WIDTH, BUT_HEIGHT));
	m_creditsDef.setOrigin(BUT_WIDTH / 2, BUT_HEIGHT / 2);
	m_creditsDef.setPosition(m_creditsPos);
}

sf::Text Menus::getGameTitle()
{
	return m_gameTitle;
}

sf::RectangleShape Menus::getMainPlay()
{
	return m_playDef;
}

sf::RectangleShape Menus::getMainSound()
{
	return m_soundDef;
}

sf::RectangleShape Menus::getMainHelp()
{
	return m_helpDef;
}

sf::RectangleShape Menus::getMainCredits()
{
	return m_creditsDef;
}
