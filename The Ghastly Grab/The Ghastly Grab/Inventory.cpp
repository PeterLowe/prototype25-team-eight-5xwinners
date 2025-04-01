#include "Inventory.h"

Inventory::Inventory()
//constructor
{
	inventoryOpen = false;

	loadImage();
}

void Inventory::loadImage()
//loads inventory sprites from files
{
	//inventory icon
	if (!m_buttonTexture.loadFromFile("ASSETS/IMAGES/INVENTORY.png"))
	{
		std::cout << "error with inventory icon image file";
	}

	m_button.setTexture(m_buttonTexture);
	m_button.setPosition(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT - 100.0f);

	//radio
	if (!m_radioTexture.loadFromFile("ASSETS/IMAGES/RADIO_BAR.png"))
	{
		std::cout << "error with inventory radio image file";
	}

	m_radio.setTexture(m_radioTexture);
	m_radio.setPosition(100.0f, 50.0f);
	m_radio.setTextureRect(sf::IntRect{ 0, 0, 800, 100 });

	//background
	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/INVENTORY_BACKGROUND.png"))
	{
		std::cout << "error with inventory background image file";
	}

	m_background.setTexture(m_backgroundTexture);

	//items
	if (!m_itemsTexture.loadFromFile("ASSETS/IMAGES/INVENTORY_ITEMS.png"))
	{
		std::cout << "error with iventory items image file";
	}

	m_key.setTexture(m_itemsTexture);
	m_key.setTextureRect(sf::IntRect{ 0, 0, 141, 141 });
	m_key.setPosition(100.0f, 220.0f);
	m_note.setTexture(m_itemsTexture);
	m_note.setTextureRect(sf::IntRect{ 0, 141, 141, 141 });
	m_note.setPosition(100.0f, 450.0f);
	m_shovel.setTexture(m_itemsTexture);
	m_shovel.setTextureRect(sf::IntRect{ 0, 282, 141, 141 });
	m_shovel.setPosition(472.66f, 220.0f);
	m_crowBar.setTexture(m_itemsTexture);
	m_crowBar.setTextureRect(sf::IntRect{ 0, 423, 141, 141 });
	m_crowBar.setPosition(472.66f, 450.0f);
}

void Inventory::keyEffect()
//for sound read out
{

}

void Inventory::noteEffect()
//for sound read out
{

}

void Inventory::shovelEffect()
//for sound read out
{

}

void Inventory::crowBarEffect()
//for sound read out
{

}

void Inventory::haveKey()
//changes sprite appearance
{
	m_key.setTextureRect(sf::IntRect{ 141, 0, 141, 141 });
}

void Inventory::haveNote()
//changes sprite appearance
{
	m_note.setTextureRect(sf::IntRect{ 141, 141, 141, 141 });
}

void Inventory::haveShovel()
//changes sprite appearance
{
	m_shovel.setTextureRect(sf::IntRect{ 141, 282, 141, 141 });
}

void Inventory::haveCrowBar()
//changes sprite appearance
{
	m_crowBar.setTextureRect(sf::IntRect{ 141, 423, 141, 141 });
}

void Inventory::radioAnimate()
//animates the radio static
{
	int frame = 0;
	const int FRAME_WIDTH = 800;
	const int FRAME_HEIGTH = 100;

	m_radioFrameCount = m_radioFrameCount + m_radioFrameIncrement; //incrementt frame
	frame = static_cast<int>(m_radioFrameCount);

	if (frame >= m_RADIO_FRAMES) //when at last frame reset to begining
	{
		frame = 0;
		m_radioFrameCount = 0.0f;
	}
	if (frame != m_radioFrame) //if frame different than previous frame nomber change frame
	{
		m_radioFrame = frame;
		m_radio.setTextureRect(sf::IntRect{ frame * FRAME_WIDTH, 0, FRAME_WIDTH, FRAME_HEIGTH }); //sprite sheet change frame
	}
}

void Inventory::changeOpen()
//changes the inventories status - closed becomes open, open becomes closed
{
	inventoryOpen = !inventoryOpen;
}

bool Inventory::getOpen()
//returns inventory open status
{
	return inventoryOpen;
}

sf::Sprite Inventory::getButton()
//returns sprite
{
	return m_button;
}

sf::Sprite Inventory::getRadio()
//returns sprite
{
	return m_radio;
}

sf::Sprite Inventory::getBackground()
//returns sprite
{
	return m_background;
}

sf::Sprite Inventory::getItems(int t_index)
//returns sprites
{
	sf::Sprite sprite;

	switch (t_index)
	{
	case 1:
	{
		sprite = m_key;
		break;
	}
	case 2:
	{
		sprite = m_note;
		break;
	}
	case 3:
	{
		sprite = m_shovel;
		break;
	}
	case 4:
	{
		sprite = m_crowBar;
		break;
	}
	}

	return sprite;
}