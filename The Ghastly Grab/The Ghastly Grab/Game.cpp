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
		if (sf::Event::MouseButtonPressed == newEvent.type)	// user pressed mouse button
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) // Main Menu
	{
		Menus.chooseScreen(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) // Gameplay Screen
	{
		Menus.chooseScreen(2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) // Inventory Screen
	{
		Menus.chooseScreen(3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) // Help Screen
	{
		Menus.chooseScreen(4);
	}

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

	checkClick();
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
}

//draw the frame and then switch buffers
void Game::render()
{
	m_window.clear(sf::Color::White);

	if (!m_riches[0].getClicked())
	{
		m_window.draw(m_riches[0].getBody());
	}

	if (Menus.currentScreen() == "MainMenu")
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

	if (Menus.currentScreen() == "Help")
	{
		m_window.draw(Menus.getHelpReturn());
		m_window.draw(Menus.getHelpInfo());
		m_window.draw(Menus.getReturnText());
	}

	if (Menus.currentScreen() == "Inventory")
	{
		m_window.draw(Menus.getInvWindow());
		m_window.draw(Menus.getInvReturn());
		m_window.draw(Menus.getInvReturnText());
	}
	if (Menus.currentScreen() == "Gameplay")
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
	m_window.draw(m_player.getBody());
	
	m_window.draw(m_meter.getBody());

	m_window.display();
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
	m_riches[0].setupSprite();
	m_meter.setupSprite();
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


void Game::checkClick()
{
	sf::FloatRect bounds = m_riches[0].getBody().getGlobalBounds();
	if (bounds.contains(m_mousePressed))
	{
		m_riches[0].onClick();

		for (int i = 0; i < MAX_RICHES; i++)
		{
			if (m_riches[i].getClicked())
			{
				Hud.itemObtained(i+1);
			}
		}
	}
	else 
	{
		m_meter.onClick();
	}
}