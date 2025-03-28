//author team_8 - [5xWinners]
#pragma once

#include "Globals.h" //include Global header file

#include "SFML/Graphics.hpp"
#include <iostream>

class Inventory
{
public:
	Inventory();
	void loadImage();

	void changeOpen();
	sf::Sprite returnButton();
	sf::Sprite returnBackground();
	sf::Sprite returnItems(int t_index);

	bool getOpen();

private:
	bool inventoryOpen;

	sf::Texture m_buttonTexture;
	sf::Sprite m_button;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_background;

	sf::Texture m_itemsTexture;
	sf::Sprite m_key;
	sf::Sprite m_note;
	sf::Sprite m_shovel;
	sf::Sprite m_crowBar;
};

