//author team_8 - [5xWinners]

#include "Rooms.h"

Rooms::Rooms()
{
	loadBackgrounds();
}


/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Rooms::loadBackgrounds()
{
	if (!m_outsideTexture.loadFromFile("ASSETS/IMAGES/outside.png"))
	{
		std::cout << "error with outside image file";
	}

	if (!m_kitchenTexture.loadFromFile("ASSETS/IMAGES/kitchen.png"))
	{
		std::cout << "error with kitchen image file";
	}

	if (!m_greenHouseTexture.loadFromFile("ASSETS/IMAGES/GREENHOUSE.png"))
	{
		std::cout << "error with GREENHOUSE image file";
	}

	if (!m_bathroomTexture.loadFromFile("ASSETS/IMAGES/BATHROOM_BACKGROUND.png"))
	{
		std::cout << "error with BATHROOM image file";
	}

	if (!m_bedroomLeftTexture.loadFromFile("ASSETS/IMAGES/BEDROOM_1.png"))
	{
		std::cout << "error with BEDROOM LEFT image file";
	}
	if (!m_bedroomRightTexture.loadFromFile("ASSETS/IMAGES/BEDROOM_2.png"))
	{
		std::cout << "error with BEDROOm RIGHT image file";
	}

	if (!m_outsideNoDoorTexture.loadFromFile("ASSETS/IMAGES/Outside_no_door.png"))
	{
		std::cout << "error with No door outside image file";
	}

	m_background.setTexture(m_outsideTexture);
}

void Rooms::roomChange(int t_room)
{
	switch (t_room)
	{
	case OUTSIDE:
		m_background.setTexture(m_outsideTexture);
		break;
	case GREENHOUSE:
		m_background.setTexture(m_greenHouseTexture);
		break;
	case HALLWAY_LEFT:
		break;
	case HALLWAY_RIGHT:
		break;
	case KITCHEN:
		m_background.setTexture(m_kitchenTexture);
		break;
	case LIVING:
		break;
	case BEDROOM_LEFT:
		m_background.setTexture(m_bedroomLeftTexture);
		break;
	case BEDROOM_RIGHT:
		m_background.setTexture(m_bedroomRightTexture);
		break;
	case BATHROOM:
		m_background.setTexture(m_bathroomTexture);
		break;
	case OUTSIDE_NO_DOOR:
		m_background.setTexture(m_outsideNoDoorTexture);
		break;
	}
}


sf::Sprite Rooms::getBackground()
{
	return m_background;
}