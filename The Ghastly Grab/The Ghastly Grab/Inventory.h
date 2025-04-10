//author Marie-Elise Ghijsen
#pragma once

#include "Globals.h" //include Global header file

#include "SFML/Graphics.hpp"
#include <iostream>

class Inventory
{
public:
	Inventory();
	void loadImage();
	void setupFontAndText();

	void changeOpen();

	void haveKey();
	void haveNote();
	void haveShovel();
	void haveCrowBar();

	void radioAnimate();

	void keyEffect();
	void noteEffect();
	void shovelEffect();
	void crowBarEffect();

	sf::Sprite getButton();
	sf::Sprite getRadio();
	sf::Sprite getBackground();
	sf::Sprite getItems(int t_index);
	sf::Text getKeyText();
	sf::Text getNoteText();
	sf::Text getShovelText();
	sf::Text getCrowBarText();

	bool getOpen();

private:
	bool inventoryOpen;

	sf::Texture m_buttonTexture;
	sf::Sprite m_button;

	sf::Texture m_radioTexture;
	sf::Sprite m_radio;
	int m_radioFrame{ -1 }; //change immediatly
	const int m_RADIO_FRAMES = 3; //amount of frames
	float m_radioFrameCount = 0.0f;
	float m_radioFrameIncrement = 0.1f; //added to frame count every clock tick

	sf::Texture m_backgroundTexture;
	sf::Sprite m_background;

	sf::Texture m_itemsTexture;
	sf::Sprite m_key;
	sf::Sprite m_note;
	sf::Sprite m_shovel;
	sf::Sprite m_crowBar;

	sf::Font m_ArialBlackfont;
	sf::Text m_keyText;
	std::string m_keyString;
	sf::Text m_noteText;
	std::string m_noteString;
	sf::Text m_shovelText;
	std::string m_shovelString;
	sf::Text m_crowBarText;
	std::string m_crowBarString;
};