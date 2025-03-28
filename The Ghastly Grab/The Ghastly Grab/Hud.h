#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>

class Hud
{

private:
	sf::RectangleShape m_testBackBoard;
	sf::RectangleShape m_testcrossOut;

	sf::Text m_item1;
	sf::Text m_item2;
	sf::Text m_item3;
	sf::Text m_item4;
	sf::Text m_item5;
	sf::Text m_item6;
	sf::Text m_item7;
	sf::Text m_item8;
	sf::Text m_item9;

	sf::Font m_font;

	sf::Texture m_backGround;
	sf::Texture m_crossOut;
	sf::Texture m_border;

	sf::Sound m_crossOutSFX;

	bool m_hudDisplay = false;

	int m_itemText[3][3] = {
		{ 1, 2, 3, },
		{ 4, 5, 6, },
		{ 7, 8, 9, }, };

public:
	Hud();

	void setupContent();
	void setupText();
	void on();
	void off();
	void itemObtained(int t_itemNum);
	bool display();
	sf::RectangleShape getBackground();
	sf::Text getItem1();
	sf::Text getItem2();
	sf::Text getItem3();
	sf::Text getItem4();
	sf::Text getItem5();
	sf::Text getItem6();
	sf::Text getItem7();
	sf::Text getItem8();
	sf::Text getItem9();

};


