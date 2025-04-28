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

	loadMusic();
}

void Rooms::loadMusic()
{
	// lOADING BACKGROUND MUSIC BUFFERS

	// outside / greenhouse
	if (!m_outsideMusic.loadFromFile("ASSETS\\AUDIO\\outside.ogg"))
	{
		std::cout << "outside Music no load"; // error
	}

	if (!m_hallMusic.loadFromFile("ASSETS\\AUDIO\\cynthia.ogg"))
	{
		std::cout << "hall Music no load"; // error
	}

	// same as hallways?
	if (!m_kitchenMusic.loadFromFile("ASSETS\\AUDIO\\cynthia.ogg"))
	{
		std::cout << "kitchen Music no load"; // error
	}

	// bed music
	if (!m_bedMusic.loadFromFile("ASSETS\\AUDIO\\cynthia.ogg"))
	{
		std::cout << "bed Music no load"; // error
	}

	// bath music
	if (!m_bathMusic.loadFromFile("ASSETS\\AUDIO\\cynthia.ogg"))
	{
		std::cout << "bath music no load"; // error
	}

	// same as kitchen/ hallways? 
	if (!m_livingMusic.loadFromFile("ASSETS\\AUDIO\\fireplace.ogg"))
	{
		std::cout << "living room music no load"; // error
	}

	if (!m_doorOneBuffer.loadFromFile("ASSETS\\AUDIO\\door1.ogg"))
	{
		std::cout << "door 1 no load"; // error
	}

	if (!m_doorTwoBuffer.loadFromFile("ASSETS\\AUDIO\\door2.ogg"))
	{
		std::cout << "door 2 no load"; // error
	}

	m_bgMusic.setVolume(20.f);
	m_bgMusic.setLoop(true);
}

void Rooms::roomChange(int t_room)
//switches between rooms
{
	switch (t_room)
	{
	case OUTSIDE:
	{
		m_background.setTexture(m_outsideTexture);
		m_bgMusic.setBuffer(m_outsideMusic);
		int door = rand() % 2;
		if (door == 0)
		{
			m_door.setBuffer(m_doorOneBuffer);
		}
		else
		{
			m_door.setBuffer(m_doorTwoBuffer);
		}

		m_door.play();
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
		m_bgMusic.setBuffer(m_hallMusic);
		break;
	}
	case HALLWAY_RIGHT:
	{
		m_background.setTexture(m_hallwayRightTexture);
		m_bgMusic.setBuffer(m_hallMusic);
		break;
	}
	case KITCHEN:
	{
		m_background.setTexture(m_kitchenTexture);
		m_bgMusic.setBuffer(m_kitchenMusic);
		break;
	}
	case LIVING:
	{
		m_background.setTexture(m_livingTexture);
		m_bgMusic.setBuffer(m_livingMusic);
		break;
	}
	case BEDROOM_LEFT:
	{
		m_background.setTexture(m_bedroomLeftTexture);
		m_bgMusic.setBuffer(m_bedMusic);
		break;
	}
	case BEDROOM_RIGHT:
	{
		m_background.setTexture(m_bedroomRightTexture);
		m_bgMusic.setBuffer(m_bedMusic);
		break;
	}
	case BATHROOM:
	{
		m_background.setTexture(m_bathroomTexture);
		m_bgMusic.setBuffer(m_bathMusic);
		break;
	}
	case OUTSIDE_NO_DOOR:
	{
		m_background.setTexture(m_outsideNoDoorTexture);
		m_bgMusic.setBuffer(m_outsideMusic);
		break;
	}
	}
}


sf::Sprite Rooms::getBackground()
//returns background texture
{
	return m_background;
}