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
	int facing = 0;

	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

	screenSwitchKeys();

	if (bounaryCheck()) //check bounds before moving
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			facing = UP;
			m_player.movement(facing);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			facing = DOWN;
			m_player.movement(facing);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			facing = LEFT;
			m_player.movement(facing);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			facing = RIGHT;
			m_player.movement(facing);
		}
		//temp
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			Hud.on();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			Hud.off();
		}
	}
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

void Game::processMiniMouse(sf::Event t_event)
{
	m_mousePressed.x = static_cast<float>(t_event.mouseButton.x);
	m_mousePressed.y = static_cast<float>(t_event.mouseButton.y);
	//m_pipe.setClickPos(m_mousePressed);
	m_pipe.rotate(m_mousePressed);
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
	if (m_inventory.getOpen())
	{
		m_inventory.radioAnimate();
	}
	//std::cout << m_screen << std::endl;
}

//draw the frame and then switch buffers
void Game::render()
{
	m_window.clear(sf::Color::White);

	for (int index = 0; index < MAX_RICHES; index++)
	{
		if (!m_riches[index].getClicked())
		{
			m_window.draw(m_riches[index].getBody());
		}
	}

	renderScreens();

	if (m_screen == GAMEPLAY)
	{
		m_window.draw(m_inventory.getButton());
	}

	m_window.draw(m_player.getBody());
	
	m_window.draw(m_meter.getBody());

	if (m_screen == INVENTORY)
	{
		renderInventory();
	}

	//if (m_screen == something)
	//{

	//}
	for (int i = 0; i < MAX_TOOLS; i++)
	{
		m_window.draw(m_tools[i].getBody());
	}

	m_window.display();
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

bool Game::bounaryCheck()
//stops player from moving out the gameplay bounds
{
	bool move = true;
	sf::Vector2f pos = m_player.getPosition();

	if (pos.y < 0.0f)
	{
		move = false;
		pos = { pos.x, 0.0f };
		m_player.setPoosition(pos);
	}
	if (pos.y > SCREEN_HEIGHT - 32)
	{
		move = false;
		pos = { pos.x,(SCREEN_HEIGHT - 32) };
		m_player.setPoosition(pos);
	}
	if (pos.x < 0.0f)
	{
		move = false;
		pos = { 0.0f, pos.y };
		m_player.setPoosition(pos);
	}
	if (pos.x > SCREEN_WIDTH - 32)
	{
		move = false;
		pos = { (SCREEN_WIDTH - 32), pos.y };
		m_player.setPoosition(pos);
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);

	return move;
}

void Game::setUp()
{
	setupAudio();
	sf::IntRect richesTextureRect;
	for (int index = 0; index < MAX_RICHES; index++)
	{
		switch (index)
		{
		case 0:
			richesTextureRect = { 0, 0, 54, 66 };
			break;
		case 1:
			richesTextureRect = { 0, 68, 64, 60 };
			break;
		case 2:
			richesTextureRect = { 0, 132, 65, 60 };
			break;
		case 3:
			richesTextureRect = { 0, 194, 54, 66 };
			break;
		case 4:
			richesTextureRect = { 0, 260 , 64 , 60 };
			break;
		case 5 :
			richesTextureRect = { 0 , 320, 70, 64 };
			break;
		case 6 :
			richesTextureRect = { 0 , 386, 64, 90 };
			break;
		case 7:
			richesTextureRect = { 0 , 480, 64, 30 };
			break;
		default:
			richesTextureRect = { 0, 510, 96, 32 };
			break;
		}
		m_riches[index].setupSprite(richesTextureRect);
		
	}
	m_meter.setupSprite();
	for (int i = 0; i < MAX_TOOLS; i++)
	{
		m_tools[i].setupSprite(i + 1);
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

	if (m_screen == HELP)
	{
		m_window.draw(Menus.getHelpReturn());
		m_window.draw(Menus.getHelpInfo());
		m_window.draw(Menus.getReturnText());
	}

	if (m_screen == INVENTORY)
	{
		m_window.draw(Menus.getInvWindow());
		m_window.draw(Menus.getInvReturn());
		m_window.draw(Menus.getInvReturnText());
	}
	if (m_screen == GAMEPLAY)
	{
		m_window.draw(Menus.getItemList());
		m_window.draw(Menus.getBagIcon());
		m_window.draw(Hud.getBackground());
		m_window.draw(Hud.getItem1());
		m_window.draw(Hud.getItem2());
		m_window.draw(Hud.getItem3());
		m_window.draw(Hud.getItem4());
		m_window.draw(Hud.getItem5());
		m_window.draw(Hud.getItem6());
		m_window.draw(Hud.getItem7());
		m_window.draw(Hud.getItem8());
		m_window.draw(Hud.getItem9());
	}

	if (m_screen == SOUND)
	{

	}

	if (m_screen == CREDITS)
	{

	}

	if (m_screen == LOSING)
	{

	}

	if (m_screen == WINNING)
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
	{
		miniGame();
	}
}

void Game::gamePlayClick()
{
	sf::FloatRect inventoryButton = m_inventory.getButton().getGlobalBounds();
	//currently getting based off inventory sprites - change to game sprite later
	sf::FloatRect key = m_inventory.getItems(1).getGlobalBounds();
	sf::FloatRect note = m_inventory.getItems(2).getGlobalBounds();
	sf::FloatRect shovel = m_inventory.getItems(3).getGlobalBounds();
	sf::FloatRect crowBar = m_inventory.getItems(4).getGlobalBounds();


	for (int index = 0; index < MAX_RICHES; index++)
	{
		sf::FloatRect bounds = m_riches[index].getBody().getGlobalBounds();

		if (bounds.contains(m_mousePressed))
		{
			m_riches[index].onClick();
			Hud.itemObtained(index + 1);
		}
	}

	if (key.contains(m_mousePressed))
	{
		m_inventory.haveKey();
	}
	else if (note.contains(m_mousePressed))
	{
		m_inventory.haveNote();
	}
	else if (shovel.contains(m_mousePressed))
	{
		m_inventory.haveShovel();
	}
	else if (crowBar.contains(m_mousePressed))
	{
		m_inventory.haveCrowBar();
	}
	else if (inventoryButton.contains(m_mousePressed))
	{
		m_screen = INVENTORY;
	}
	else 
	{
		m_meter.onClick();
	}
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

void Game::miniGame()
{
	sf::RenderWindow window2(sf::VideoMode{ 800U, 640U, 32U }, "Mini Game");
	sf::Event newEvent{};

	while (window2.isOpen())
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window2.close();
		}

		if (sf::Event::MouseButtonReleased == newEvent.type)
		{
			processMouse(newEvent);
		}

		//if (something == something)
		//{
		m_pipe.render(window2);
		m_pipe.update();
		//}

		//window2.display();
	}

}

