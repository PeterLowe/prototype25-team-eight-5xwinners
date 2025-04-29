#include "Inventory.h"

Inventory::Inventory()
//constructor
{
	inventoryOpen = false;

	m_keyString = "Turn over every...";
	m_noteString = "Not a recipe!";
	m_shovelString = "Whatever would you \nuse this for?";
	m_crowBarString = "Put away amongst \nthe fauna...";

	loadImage();
	setupFontAndText();
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

	//key text
	m_key.setTexture(m_itemsTexture);
	m_key.setTextureRect(sf::IntRect{ 0, 0, 141, 141 });
	m_key.setPosition(100.0f, 220.0f);
	//note text
	m_note.setTexture(m_itemsTexture);
	m_note.setTextureRect(sf::IntRect{ 0, 141, 141, 141 });
	m_note.setPosition(100.0f, 450.0f);
	//shovel text
	m_shovel.setTexture(m_itemsTexture);
	m_shovel.setTextureRect(sf::IntRect{ 0, 282, 141, 141 });
	m_shovel.setPosition(472.66f, 220.0f);
	//crowBar text
	m_crowBar.setTexture(m_itemsTexture);
	m_crowBar.setTextureRect(sf::IntRect{ 0, 423, 141, 141 });
	m_crowBar.setPosition(472.66f, 450.0f);
}

void Inventory::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	//key text
	m_keyText.setCharacterSize(20U);
	m_keyText.setPosition(250.0f, 220.0f);
	m_keyText.setFillColor(sf::Color::Black);
	m_keyText.setFont(m_ArialBlackfont);
	m_keyText.setString(m_keyString);
	//note text
	m_noteText.setCharacterSize(20U);
	m_noteText.setPosition(250.0f, 450.0f);
	m_noteText.setFillColor(sf::Color::Black);
	m_noteText.setFont(m_ArialBlackfont);
	m_noteText.setString(m_noteString);
	//shovel text
	m_shovelText.setCharacterSize(20U);
	m_shovelText.setPosition(622.66f, 220.0f);
	m_shovelText.setFillColor(sf::Color::Black);
	m_shovelText.setFont(m_ArialBlackfont);
	m_shovelText.setString(m_shovelString);
	//crowBar text
	m_crowBarText.setCharacterSize(20U);
	m_crowBarText.setPosition(622.66f, 450.0f);
	m_crowBarText.setFillColor(sf::Color::Black);
	m_crowBarText.setFont(m_ArialBlackfont);
	m_crowBarText.setString(m_crowBarString);
}

void Inventory::keyEffect()
//for sound read out
{
	if (m_haveKey)
	{
		m_voiceline.setBuffer(m_keyUse);
	}
	else
	{
		m_voiceline.setBuffer(m_keyFind);
	}

	m_voiceline.play();
}

void Inventory::noteEffect()
//for sound read out
{
	if (m_haveNote)
	{
		m_voiceline.setBuffer(m_noteUse);
	}
	else
	{
		m_voiceline.setBuffer(m_noteFind);
	}

	m_voiceline.play();
}

void Inventory::shovelEffect()
//for sound read out
{
	m_voiceline.setBuffer(m_shovelLine);
	m_voiceline.play();
}

void Inventory::crowBarEffect()
//for sound read out
{
	if (m_haveCrowbar)
	{
		m_voiceline.setBuffer(m_crowbarUse);
	}
	else
	{
		m_voiceline.setBuffer(m_crowbarFind);
	}

	m_voiceline.play();
}

void Inventory::loadVoice()
// loads the voicelines
{
	if (!m_keyUse.loadFromFile("ASSETS\\AUDIO\\keyUse.ogg"))
	{
		std::cout << "key use voiceline no load"; // error
	}

	if (!m_keyFind.loadFromFile("ASSETS\\AUDIO\\keyFind.ogg"))
	{
		std::cout << "key Find voiceline no load"; // error
	}
	
	if (!m_noteUse.loadFromFile("ASSETS\\AUDIO\\noteUse.ogg"))
	{
		std::cout << "note use voiceline no load"; // error
	}
	
	if (!m_noteFind.loadFromFile("ASSETS\\AUDIO\\noteFind.ogg"))
	{
		std::cout << "note Find voiceline no load"; // error
	}

	if (!m_crowbarFind.loadFromFile("ASSETS\\AUDIO\\crowbarFind.ogg"))
	{
		std::cout << "crowbar Find voiceline no load"; // error
	}
	
	//if (!m_crowbarUse.loadFromFile("ASSETS\\AUDIO\\crowbarUse.ogg"))
	//{
	//	std::cout << "crowbar use voiceline no load"; // error
	//}
	
		if (!m_shovelLine.loadFromFile("ASSETS\\AUDIO\\shovelLine.ogg"))
	{
		std::cout << "shovel voiceline no load"; // error
	}


}

void Inventory::haveKey()
//changes sprite and text appearance
{
	m_key.setTextureRect(sf::IntRect{ 141, 0, 141, 141 });
	m_keyString = "My my my \nwhat a lovely door \nyouve got!";
	m_keyText.setString(m_keyString);
	m_haveKey = true;
}

void Inventory::haveNote()
//changes sprite and text appearance
{
	m_note.setTextureRect(sf::IntRect{ 141, 141, 141, 141 });
	m_noteString = "A combination?";
	m_noteText.setString(m_noteString);
	m_haveNote = true;
}

void Inventory::haveShovel()
//changes sprite and text appearance
{
	m_shovel.setTextureRect(sf::IntRect{ 141, 282, 141, 141 });
	m_shovelString = "Whatever would you \nuse this for? ;)";
	m_shovelText.setString(m_shovelString);
}

void Inventory::haveCrowBar()
//changes sprite and text appearance
{
	m_crowBar.setTextureRect(sf::IntRect{ 141, 423, 141, 141 });
	m_crowBarString = "You could ply \nsomething of a wall \nwith this thing...";
	m_crowBarText.setString(m_crowBarString);
	m_haveCrowbar = true;
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

sf::Text Inventory::getKeyText()
//returns text
{
	return m_keyText;
}

sf::Text Inventory::getNoteText()
//returns text
{
	return m_noteText;
}

sf::Text Inventory::getShovelText()
//returns text
{
	return m_shovelText;
}

sf::Text Inventory::getCrowBarText()
//returns text
{
	return m_crowBarText;
}