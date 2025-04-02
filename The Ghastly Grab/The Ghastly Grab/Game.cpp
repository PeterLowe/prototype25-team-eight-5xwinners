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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		facing = UP;
		m_player.movement(facing);
		m_legsRect.move(0, -5);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		facing = DOWN;
		m_player.movement(facing);
		m_legsRect.move(0, 5);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		facing = LEFT;
		m_player.movement(facing);
		m_legsRect.move(-5, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		facing = RIGHT;
		m_player.movement(facing);
		m_legsRect.move(5, 0);
	}

	bounaryCheck(facing);

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

	if (Menus.currentScreen() == "GameplayScreen")
	{
		m_window.draw(Menus.getItemList());
		m_window.draw(Menus.getBagIcon());
	}


	
	m_window.draw(m_meter.getBody());

	m_window.draw(m_bgSprite);

	m_window.draw(m_player.getBody());
	m_window.draw(m_legsRect);

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

	// Rect for legs
	m_legsRect.setFillColor(sf::Color::Yellow);
	m_legsRect.setOutlineColor(sf::Color::Black);
	m_legsRect.setOrigin(LEG_WIDTH / 2, LEG_HEIGHT / 2);
	m_legsRect.setPosition((SCREEN_WIDTH / 2) + LEFT_TO_LEG, (SCREEN_HEIGHT / 2) + UP_TO_LEG);
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

void Game::bounaryCheck(int t_facing)
//stops player from moving out the gameplay bounds
// Arceus bless me in what I am to do
{
	float legY, legX;
	legY = m_legsRect.getOrigin().y;

	legX = m_legsRect.getOrigin().x;

	//float legValue(legY * 1.706 + 337);

	//if (legY > 337 && legY < 550)
	//{
	//	if (legX < 126)
	//	{
	//		if (legY < legX * 1.706 + 337)
	//		{
	//			legX+= 5;
	//			m_legsRect.setPosition({ legX,legY });
	//		}
	//		else if (false)
	//		{
	//			//m_legsRect.setPosition({ legX--, legY });
	//		}
	//	}
	//	else if (legX > 876)
	//	{

	//	}
	//}

	if (legX < 126)
	{
		if (legY < 15)
		{
			legX+= 5;
			legY += 5;
			m_legsRect.setPosition({ legX,legY });
		}
		else if (legY < 30)
		{
			legX += 5;
			legY += 4.5;
			m_legsRect.setPosition({ legX,legY });
		}
		else if (legY < 45)
		{
			legX += 5;
			legY += 4;
			m_legsRect.setPosition({ legX,legY });
		}
		else if (legY < 60)
		{
			legX += 5;
			legY += 3.5;
			m_legsRect.setPosition({ legX,legY });
		}
		else if (legY < 75)
		{
			legX += 5;
			legY += 3;
			m_legsRect.setPosition({ legX,legY });
		}
		else if (legY < 90)
		{
			legX += 5;
			legY += 2.5;
			m_legsRect.setPosition({ legX,legY });
		}
		else if (legY < 105)
		{
			legX += 5;
			legY += 2;
			m_legsRect.setPosition({ legX,legY });
		}
		else if (legY < 120)
		{
			legX += 5;
			legY += 1.5;
			m_legsRect.setPosition({ legX,legY });
		}
	}


}