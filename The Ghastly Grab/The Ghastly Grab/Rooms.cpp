//author team_8 - [5xWinners]

#include "Rooms.h"

Rooms::Rooms()
//constructor
{
	loadBackgrounds();
}


/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Rooms::loadBackgrounds()
//loads textures and sets starting room
{
	if (!m_outsideTexture.loadFromFile("ASSETS/IMAGES/outside.png"))
	{
		std::cout << "error with outside image file";
	}

	if (!m_greenHouseTexture.loadFromFile("ASSETS/IMAGES/GREENHOUSE.png"))
	{
		std::cout << "error with GREENHOUSE image file";
	}

	if (!m_hallwayLeftTexture.loadFromFile("ASSETS/IMAGES/LEFT_HALLWAY.png"))
	{
		std::cout << "error with left hallway image file";
	}

	if (!m_hallwayRightTexture.loadFromFile("ASSETS/IMAGES/RIGHT_HALLWAY.png"))
	{
		std::cout << "error with right hallway image file";
	}

	if (!m_kitchenTexture.loadFromFile("ASSETS/IMAGES/kitchen.png"))
	{
		std::cout << "error with kitchen image file";
	}

	if (!m_bedroomLeftTexture.loadFromFile("ASSETS/IMAGES/BEDROOM_1.png"))
	{
		std::cout << "error with BEDROOM LEFT image file";
	}

	if (!m_bedroomRightTexture.loadFromFile("ASSETS/IMAGES/BEDROOM_2.png"))
	{
		std::cout << "error with BEDROOm RIGHT image file";
	}

	if (!m_bathroomTexture.loadFromFile("ASSETS/IMAGES/BATHROOM_BACKGROUND.png"))
	{
		std::cout << "error with BATHROOM image file";
	}

	//load alternative rooms
	if (!m_outsideNoDoorTexture.loadFromFile("ASSETS/IMAGES/Outside_no_door.png"))
	{
		std::cout << "error with No door outside image file";
	}

	//set starting room
	m_background.setTexture(m_outsideTexture);
}


void Rooms::roomChange(int t_room)
//switches between rooms
{
	switch (t_room)
	{
	case OUTSIDE:
	{
		m_background.setTexture(m_outsideTexture);
		break;
	}
	case GREENHOUSE:
	{
		m_background.setTexture(m_greenHouseTexture);
		break;
	}
	case HALLWAY_LEFT:
	{
		m_background.setTexture(m_hallwayLeftTexture);
		break;
	}
	case HALLWAY_RIGHT:
	{
		m_background.setTexture(m_hallwayRightTexture);
		break;
	}
	case KITCHEN:
	{
		m_background.setTexture(m_kitchenTexture);
		break;
	}
	case LIVING:
	{
		m_background.setTexture(m_livingTexture);
		break;
	}
	case BEDROOM_LEFT:
	{
		m_background.setTexture(m_bedroomLeftTexture);
		break;
	}
	case BEDROOM_RIGHT:
	{
		m_background.setTexture(m_bedroomRightTexture);
		break;
	}
	case BATHROOM:
	{
		m_background.setTexture(m_bathroomTexture);
		break;
	}
	case OUTSIDE_NO_DOOR:
	{
		m_background.setTexture(m_outsideNoDoorTexture);
		break;
	}
	}
}

sf::Sprite Rooms::getBackground()
//returns background texture
{
	return m_background;
}