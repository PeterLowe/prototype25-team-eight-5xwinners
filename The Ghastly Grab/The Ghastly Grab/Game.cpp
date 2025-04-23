//author team_8 - [5xWinners]

#include "Game.h"

//default constructor
//setup the window properties
//load and setup the text 
///oad and setup thne image
Game::Game() :
	m_window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setUp();
}

//default destructor we didn't dynamically allocate anything
//so we don't need to free it, but mthod needs to be here
Game::~Game()
{
}

//main game loop
//update 60 times per second,
//process update as often as possible and at least 60 times per second
//draw as often as possible but only updates are on time
//if updates run slow then don't render frames
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
#ifdef _DEBUG
			render(); // want to debug drawing while stepping through code
#endif // _DEBUG

		}
		render(); // as many as possible
	}
}

//handle user and system events/ input
//get key presses/ mouse moves etc. from OS
//and user :: Don't do game update here
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		if (sf::Event::MouseButtonReleased == newEvent.type)	// user pressed mouse button
		{
			processMouse(newEvent);
		}
	}
}

///deal with key presses from the user
//<param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

	screenSwitchKeys();
}

/// <summary>
/// deal with mouses presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processMouse(sf::Event t_event)
{

	m_mousePressed.x = static_cast<float>(t_event.mouseButton.x);
	m_mousePressed.y = static_cast<float>(t_event.mouseButton.y);

	screenSwitchButtons();

	if (m_screen == GAMEPLAY)
	{
		gamePlayClick();
	}
	else if (m_screen == INVENTORY)
	{
		inventoryClick();
	}
}



/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (t_deltaTime.asMilliseconds() != 16)
	{
		std::cout << "time warp" << std::endl; // expecting 60 fps of action
	}
	if (m_exitGame)
	{
		m_window.close();
	}

	playerMovement();

	if (m_screen == INVENTORY)
	{
		m_inventory.radioAnimate();
	}
	//std::cout << m_screen << std::endl;
}

//draw the frame and then switch buffers
void Game::render()
{
	m_window.clear(sf::Color::White);
	
	renderScreens();

	m_window.display();
}

void Game::renderGamePlay()
{
	m_window.draw(m_roomBG.getBackground());

	renderTools();
	renderRiches();
	renderCovers();

	m_window.draw(m_player.getBody());

	m_window.draw(Hud.getBackground());
	m_window.draw(Menus.getItemList());
	m_window.draw(Menus.getBagIcon());
	m_window.draw(Hud.getItem1());
	m_window.draw(Hud.getItem2());
	m_window.draw(Hud.getItem3());
	m_window.draw(Hud.getItem4());
	m_window.draw(Hud.getItem5());
	m_window.draw(Hud.getItem6());
	m_window.draw(Hud.getItem7());
	m_window.draw(Hud.getItem8());
	m_window.draw(Hud.getItem9());

	m_window.draw(m_inventory.getButton());
	m_window.draw(m_meter.getBody());
}

void Game::renderRiches()
{
	switch (m_room)
	{
	case OUTSIDE:
		break;
	case GREENHOUSE:
		break;
	case HALLWAY_LEFT:
		break;
	case HALLWAY_RIGHT:
		break;
	case KITCHEN:
		break;
	case LIVING:
		break;
	case BEDROOM_LEFT:
		break;
	case BEDROOM_RIGHT:
		break;
	case BATHROOM:
		break;
	}
}

void Game::renderCovers()
{
	switch (m_room)
	{
	case OUTSIDE:
		m_window.draw(m_covers[0].getBody());
		break;
	case GREENHOUSE:
		break;
	case HALLWAY_LEFT:
		break;
	case HALLWAY_RIGHT:
		break;
	case KITCHEN:
		break;
	case LIVING:
		break;
	case BEDROOM_LEFT:
		break;
	case BEDROOM_RIGHT:
		break;
	case BATHROOM:
		break;
	}
}


void Game::renderTools()
{
	switch (m_room)
	{
	case OUTSIDE:
		m_window.draw(m_tools[0].getBody());
		break;
	case GREENHOUSE:
		break;
	case HALLWAY_LEFT:
		break;
	case HALLWAY_RIGHT:
		break;
	case KITCHEN:
		break;
	case LIVING:
		break;
	case BEDROOM_LEFT:
		break;
	case BEDROOM_RIGHT:
		break;
	case BATHROOM:
		break;
	}
}

void Game::renderInventory()
{
	m_window.draw(m_inventory.getBackground());
	m_window.draw(m_inventory.getButton());
	m_window.draw(m_inventory.getRadio());

	for (int index = 1; index < MAX_TOOLS + 1; index++)
	{
		m_window.draw(m_inventory.getItems(index));
	}

	m_window.draw(m_inventory.getKeyText());
	m_window.draw(m_inventory.getNoteText());
	m_window.draw(m_inventory.getShovelText());
	m_window.draw(m_inventory.getCrowBarText());
}

void Game::setUp()
{
	setupAudio();
	
	m_meter.setupSprite();

	if (!m_bgTexture.loadFromFile("ASSETS/IMAGES/BG.png"))
	{
		std::cout << "Error with BG" << std::endl;
	}

	m_bgSprite.setTexture(m_bgTexture);

	for (int i = 0; i < MAX_TOOLS; i++)
	{
		m_tools[i].setupSprite(i + 1);
	}

	for (int i = 0; i < MAX_RICHES; i++)
	{
		m_riches[i].setupSprite(i);
	}

	for (int i = 0; i < MAX_COVERS; i++)
	{
		m_covers[i].setupSprite(i);
	}

}

/// <summary>
/// load the background music which is to be played constantly
/// </summary>
void Game::setupAudio()
{
	{
		if (!m_bgMusic.openFromFile("ASSETS\\AUDIO\\cynthia.ogg"))
		{
			std::cout << "Music no load"; // error
		}

		m_bgMusic.setVolume(20.f);
		m_bgMusic.setLoop(true);
		m_bgMusic.play();
	}
}

/// <summary>
/// Draws objects from Menu class to screen
/// </summary>
void Game::renderScreens()
{
	if (m_screen == MAIN)
	{
		m_window.draw(Menus.getGameTitle());
		m_window.draw(Menus.getMainPlay());
		m_window.draw(Menus.getMainSound());
		m_window.draw(Menus.getMainHelp());
		m_window.draw(Menus.getMainCredits());

		// Temp
		m_window.draw(Menus.getPlayText());
		m_window.draw(Menus.getSoundText());
		m_window.draw(Menus.getHelpText());
		m_window.draw(Menus.getCreditsText());
		//
	}
	else if (m_screen == HELP)
	{
		m_window.draw(Menus.getHelpReturn());
		m_window.draw(Menus.getHelpInfo());
		m_window.draw(Menus.getReturnText());
	}
	else if (m_screen == INVENTORY)
	{
		renderInventory();

		m_window.draw(Menus.getInvReturn());
		m_window.draw(Menus.getInvReturnText());
	}
	else if (m_screen == GAMEPLAY)
	{
		renderGamePlay();
	}
	else if (m_screen == SOUND)
	{

	}
	else if (m_screen == CREDITS)
	{

	}
	else if (m_screen == LOSING)
	{

	}
	else if (m_screen == WINNING)
	{

	}
}

void Game::screenSwitchButtons()
{
	if (m_screen == MAIN)
	{
		m_screen = Menus.clickMenu(m_mousePressed);
	}
}

/// <summary>
/// Switch between gameplay screens using numerical key press
/// </summary>
void Game::screenSwitchKeys()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) // Main Menu
	{
		m_screen = MAIN;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) // Gameplay
	{
		m_screen = GAMEPLAY;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) // Inventory
	{
		m_screen = INVENTORY;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) // Help
	{
		m_screen = HELP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) // Sound
	{
		m_screen = SOUND;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) // Credits
	{
		m_screen = CREDITS;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) // Losing
	{
		m_screen = LOSING;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) // Winning
	{
		m_screen = WINNING;
	}
}

void Game::gamePlayClick()
{
	sf::FloatRect inventoryButton = m_inventory.getButton().getGlobalBounds();


	if (inventoryButton.contains(m_mousePressed))
	{
		m_screen = INVENTORY;
	}
	else if (coversClick())
	{
		
	}
	else if (toolsClick())
	{

	}
	else if (richesClick())
	{

	}
	else 
	{
		m_meter.onClick();
	}
}

bool Game::coversClick()
{
	bool clicked = false;

	switch (m_room)
	{
	case OUTSIDE:
	{
		sf::FloatRect mat = m_covers[0].getBody().getGlobalBounds();
		if (mat.contains(m_mousePressed) && !m_covers[0].getClicked())
		{
			m_covers[0].onClick(0);
			clicked = true;
		}
		break;
	}
	case GREENHOUSE:
		break;
	case HALLWAY_LEFT:
		break;
	case HALLWAY_RIGHT:
		break;
	case KITCHEN:
		break;
	case LIVING:
		break;
	case BEDROOM_LEFT:
		break;
	case BEDROOM_RIGHT:
		break;
	case BATHROOM:
		break;
	}

	return clicked;
}

bool Game::toolsClick()
{
	bool clicked = false;

	switch (m_room)
	{
	case OUTSIDE:
	{
		sf::FloatRect key = m_tools[0].getBody().getGlobalBounds();
		if (key.contains(m_mousePressed) && m_covers[0].getClicked())
		{
			m_tools[0].onClick();
			m_inventory.haveKey();
			clicked = true;
		}
		break;
	}
	case GREENHOUSE:
		break;
	case HALLWAY_LEFT:
		break;
	case HALLWAY_RIGHT:
		break;
	case KITCHEN:
		break;
	case LIVING:
		break;
	case BEDROOM_LEFT:
		break;
	case BEDROOM_RIGHT:
		break;
	case BATHROOM:
		break;
	}

	return clicked;
}

bool Game::richesClick()
{
	bool clicked = false;

	switch (m_room)
	{

	case GREENHOUSE:
		break;
	case HALLWAY_LEFT:
		break;
	case HALLWAY_RIGHT:
		break;
	case KITCHEN:
		break;
	case LIVING:
		break;
	case BEDROOM_LEFT:
		break;
	case BEDROOM_RIGHT:
		break;
	case BATHROOM:
		break;
	}

	return clicked;
}

void Game::playerMovement()
{
	int facing = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		facing = UP;
		m_player.movement(facing);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		facing = DOWN;
		m_player.movement(facing);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		facing = LEFT;
		m_player.movement(facing);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		facing = RIGHT;
		m_player.movement(facing);
	}
	else
	{
		m_player.resetTexture();
	}

	m_player.bounaryCheck(facing);
}

void Game::inventoryClick()
{
	sf::FloatRect exitBounds = m_inventory.getButton().getGlobalBounds();
	sf::FloatRect key = m_inventory.getItems(1).getGlobalBounds();
	sf::FloatRect note = m_inventory.getItems(2).getGlobalBounds();
	sf::FloatRect shovel = m_inventory.getItems(3).getGlobalBounds();
	sf::FloatRect crowBar = m_inventory.getItems(4).getGlobalBounds();

	if (exitBounds.contains(m_mousePressed))
	{
		m_screen = GAMEPLAY;
	}
	else if (key.contains(m_mousePressed))
	{
		m_inventory.keyEffect();
	}
	else if (note.contains(m_mousePressed))
	{
		m_inventory.noteEffect();
	}
	else if (shovel.contains(m_mousePressed))
	{
		m_inventory.shovelEffect();
	}
	else if (crowBar.contains(m_mousePressed))
	{
		m_inventory.crowBarEffect();
	}
}
