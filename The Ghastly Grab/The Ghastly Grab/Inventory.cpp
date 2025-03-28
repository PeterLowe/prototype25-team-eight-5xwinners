#include "Inventory.h"

Inventory::Inventory()
{
	inventoryOpen = false;

	loadImage();
}

void Inventory::loadImage()
//loads inventory sprites from files
{
	if (!m_buttonTexture.loadFromFile("ASSETS/IMAGES/INVENTORY.png"))
	{
		std::cout << "error with inventory background image file";
	}

	m_button.setTexture(m_buttonTexture);

	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/INVENTORY_BACKGROUND.png"))
	{
		std::cout << "error with inventory background image file";
	}

	m_background.setTexture(m_backgroundTexture);

	if (!m_itemsTexture.loadFromFile("ASSETS/IMAGES/USABLE_ITEMS.png"))
	{
		std::cout << "error with usable items image file";
	}

	m_key.setTexture(m_itemsTexture);
	m_note.setTexture(m_itemsTexture);
	m_shovel.setTexture(m_itemsTexture);
	m_crowBar.setTexture(m_itemsTexture);
}

void Inventory::changeOpen()
{
	inventoryOpen = !inventoryOpen;
}

sf::Sprite Inventory::returnButton()
{
	return m_button;
}

sf::Sprite Inventory::returnBackground()
{
	return m_background;
}

sf::Sprite Inventory::returnItems(int t_index)
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

bool Inventory::getOpen()
{
	return inventoryOpen;
}