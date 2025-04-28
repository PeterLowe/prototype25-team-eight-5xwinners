#include "Menus.h"

// Written by Daemon
Menus::Menus() // Default constructor
{
	mainMenuShapes();
	mainMenuText();

	helpMenuShapes();
	inventoryScreen();

	gameplayScreen();
}

/// <summary>
/// Sets up graphics and bounding boxs for buttons
/// </summary>
void Menus::mainMenuShapes()
{
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

/// Temporary
void Menus::mainMenuText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "Issue loading menu font" << std::endl;
	}

	m_gameTitle.setFont(m_ArialBlackfont);
	m_gameTitle.setCharacterSize(64);
	m_gameTitle.setFillColor(sf::Color::Black);
	m_gameTitle.setString("Ghastly Grab");
	m_titleSize = m_gameTitle.getGlobalBounds();
	m_gameTitle.setOrigin(m_titleSize.width / 2, m_titleSize.height / 2);
	m_gameTitle.setPosition(m_titlePos);

	m_play.setFont(m_ArialBlackfont);
	m_play.setCharacterSize(32);
	m_play.setString("Play");
	m_playSize = m_play.getGlobalBounds();
	m_play.setOrigin((m_playSize.width / 2), (m_playSize.height / 2) + 6);
	m_play.setPosition(m_playPos);

	m_sound.setFont(m_ArialBlackfont);
	m_sound.setCharacterSize(32);
	m_sound.setString("Sound");
	m_soundSize = m_sound.getGlobalBounds();
	m_sound.setOrigin((m_soundSize.width / 2), (m_soundSize.height / 2) + 10);
	m_sound.setPosition(m_soundPos);

	m_help.setFont(m_ArialBlackfont);
	m_help.setCharacterSize(32);
	m_help.setString("Help");
	m_helpSize = m_help.getGlobalBounds();
	m_help.setOrigin((m_helpSize.width / 2), (m_helpSize.height / 2) + 6);
	m_help.setPosition(m_helpPos);

	m_credits.setFont(m_ArialBlackfont);
	m_credits.setCharacterSize(32);
	m_credits.setString("Credits");
	m_creditSize = m_credits.getGlobalBounds();
	m_credits.setOrigin((m_creditSize.width / 2), (m_creditSize.height / 2) + 8);
	m_credits.setPosition(m_creditsPos);
}

sf::Text Menus::getGameTitle()
{
	return m_gameTitle;
}

sf::Text Menus::getPlayText()
{
	return m_play;
}

sf::Text Menus::getSoundText()
{
	return m_sound;
}

sf::Text Menus::getHelpText()
{
	return m_help;
}

sf::Text Menus::getCreditsText()
{
	return m_credits;
}
/// 

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

void Menus::helpMenuShapes()
{
	m_helpReturn.setFillColor(sf::Color::Blue);
	m_helpReturn.setSize(sf::Vector2f(BUT_WIDTH, BUT_HEIGHT));
	m_helpReturn.setPosition(25, 25);

	m_helpInfo.setFillColor(sf::Color::Cyan);
	m_helpInfo.setSize(sf::Vector2f{ 758.0f, 600.0f });
	m_helpInfo.setPosition(121, 114);

	m_return.setFont(m_ArialBlackfont);
	m_return.setCharacterSize(32);
	m_return.setString("Return");
	m_return.setPosition(m_helpReturn.getPosition());
	m_returnSize = m_return.getGlobalBounds();
	m_return.setOrigin(m_returnSize.width / 2, m_returnSize.height / 2);
	m_return.setPosition(120.0f,50.0f);
}

sf::RectangleShape Menus::getHelpReturn()
{
	return m_helpReturn;
}

sf::RectangleShape Menus::getHelpInfo()
{
	return m_helpInfo;
}

sf::Text Menus::getReturnText()
{
	return m_return;
}

void Menus::gameplayScreen()
{
	m_itemList.setFillColor(sf::Color(210, 180, 140));
	m_itemList.setSize(sf::Vector2f(750, 250));
	m_itemList.setOrigin(0, 250);
	m_itemList.setPosition(0, 800);

	m_bagIcon.setFillColor(sf::Color(131, 105, 83));
	m_bagIcon.setSize(sf::Vector2f(250, 250));
	m_bagIcon.setOrigin(0, 250);
	m_bagIcon.setPosition(750,800);
}

sf::RectangleShape Menus::getItemList()
{
	return m_itemList;
}

sf::RectangleShape Menus::getBagIcon()
{
	return m_bagIcon;
}

void Menus::inventoryScreen()
{
	m_invReturnShape.setFillColor(sf::Color::Blue);
	m_invReturnShape.setSize(sf::Vector2f(BUT_WIDTH, BUT_HEIGHT));
	m_invReturnShape.setPosition(SCREEN_WIDTH - BUT_WIDTH - 50, SCREEN_HEIGHT - BUT_HEIGHT - 50);

	m_invReturnText.setFont(m_ArialBlackfont);
	m_invReturnText.setCharacterSize(32);
	m_invReturnText.setString("Return");
	m_invReturnText.setPosition(m_invReturnShape.getPosition());
	m_invReturnSize = m_invReturnShape.getGlobalBounds();
	m_invReturnText.setOrigin(m_invReturnSize.width / 2, m_invReturnSize.height / 2);
	m_invReturnText.setPosition(SCREEN_WIDTH - 110, SCREEN_HEIGHT - 70);
}

sf::RectangleShape Menus::getInvReturn()
{
	return m_invReturnShape;
}

sf::Text Menus::getInvReturnText()
{
	return m_invReturnText;
}
