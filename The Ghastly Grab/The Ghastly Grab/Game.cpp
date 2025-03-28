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
//void Game::render()
//{
//	m_window.clear(sf::Color::White);
//
//	if (!m_riches[0].getClicked())
//	{
//		m_window.draw(m_riches[0].getBody());
//	}
//
//	if (Menus.currentScreen() == "MainMenu")
//	{
//		m_window.draw(Menus.getGameTitle());
//		m_window.draw(Menus.getMainPlay());
//		m_window.draw(Menus.getMainSound());
//		m_window.draw(Menus.getMainHelp());
//		m_window.draw(Menus.getMainCredits());
//
//		// Temp
//		m_window.draw(Menus.getPlayText());
//		m_window.draw(Menus.getSoundText());
//		m_window.draw(Menus.getHelpText());
//		m_window.draw(Menus.getCreditsText());
//		//
//	}
//
//	if (Menus.currentScreen() == "Help")
//	{
//		m_window.draw(Menus.getHelpReturn());
//		m_window.draw(Menus.getHelpInfo());
//		m_window.draw(Menus.getReturnText());
//	}
//
//	if (Menus.currentScreen() == "GameplayScreen")
//	{
//		m_window.draw(Menus.getItemList());
//		m_window.draw(Menus.getBagIcon());
//	}
//
//	m_window.draw(m_player.getBody());
//	
//	m_window.draw(m_meter.getBody());
//
//	m_window.display();
//}


void Game::render()
{
	m_window.clear(sf::Color::White);

	
	m_window.draw(m_bgSprite);


	m_window.draw(invis);
	m_window.draw(diagonal1);
	m_window.draw(diagonal2);
	m_window.draw(floor);



	m_window.draw(m_player.getBody());

	m_window.display();
}

void Game::setUp()
{
	setupAudio();
	m_riches[0].setupSprite();
	m_meter.setupSprite();

	if (!m_bgTexture.loadFromFile("ASSETS/IMAGES/BG.png"))
	{
		std::cout << "Error with BG" << std::endl;
	}

	m_bgSprite.setTexture(m_bgTexture);

	setupBounds();
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
	}
	else 
	{
		m_meter.onClick();
	}
}


bool Game::bounaryCheck()
//stops player from moving out the gameplay bounds
// Arceus bless me in what I am about to do
{
	bool move = true;

	sf::Vector2f playerPos = m_player.getPosition();

	// legs - rect on player's leg, d1 - diagonal on left side, d2 - diagonal on right side, invis - rect below floor that's covered by HUD, floor, rect of visible floor.







	return move;
}


void Game::setupBounds()
{
	diagonal1.setPosition({ 128.0f,335.0f });
	diagonal1.setSize({ 110.0f, 250.0f });
	diagonal1.setRotation(31);
	diagonal1.setFillColor(sf::Color::Yellow);

	diagonal2.setPosition({ 780.5f,391.0f });
	diagonal2.setSize({ 110.0f, 250.0f });
	diagonal2.setRotation(330);
	diagonal2.setFillColor(sf::Color::Red);

	floor.setPosition({ 128.0f,337.0f });
	floor.setSize({ 747.0f , 211.0f });
	floor.setFillColor(sf::Color::Green);

	invis.setPosition({ 0.0f,548.0f });
	invis.setSize({1000.0f , 100.0f });
	invis.setFillColor(sf::Color::Blue);


}