//author team_8 - [5xWinners]

#include "Game.h"

//default constructor
//setup the window properties
//load and setup the text 
///oad and setup thne image
Game::Game() :
	m_window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT, 32U }, "Ghastly Grab" },
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

	if (m_screen == GAMEPLAY)
	{
		gamePlayClick();
	}
	else if (m_screen == INVENTORY)
	{
		inventoryClick();
	}
	else if (m_screen == MAIN)
	{
		menuClick();
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

	for (int i = 0; i < MAX_RICHES; i++)
	{	
		m_gameWin = true;
		if (!m_riches[i].getClicked())
		{
			m_gameWin = false;
			break;
		}
	}

	if (m_gameWin)
	{
		m_screen = WINNING;
	}

	if (m_screen == GAMEPLAY)
	{
		playerMovement();
	}

	m_roomBG.roomChange(m_room);

	if (m_screen == MAIN)
	{
		Menus.animateMainMenu();
	}

	if (m_screen == INVENTORY)
	{
		m_inventory.radioAnimate();
	}

	if (m_screen == LOSING)
	{
		gameOver();
	}
	else if (m_screen == WINNING)
	{
		std::cout << "You WON! (Kindly imagine this a beautiful game win screen!)" << std::endl << std::endl;
		gameWin();
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
	{
		break;
	}
	case GREENHOUSE:
	{
		if (!m_riches[4].getClicked())
		{
			m_window.draw(m_riches[4].getBody());
		}
		break;
	}
	case HALLWAY_LEFT:
	{
		if (!m_riches[8].getClicked())
		{
			m_window.draw(m_riches[8].getBody());
		}
		break;
	}
	case HALLWAY_RIGHT:
	{
		if (!m_riches[6].getClicked())
		{
			m_window.draw(m_riches[6].getBody());
		}
		break;
	}
	case KITCHEN:
	{
		break;
	}
	case LIVING:
	{
		if (!m_riches[5].getClicked())
		{
			m_window.draw(m_riches[5].getBody());
		}
		if (!m_riches[7].getClicked())
		{
			m_window.draw(m_riches[7].getBody());
		}
		break;
	}
	case BEDROOM_LEFT:
	{
		if (!m_riches[0].getClicked())
		{
			m_window.draw(m_riches[0].getBody());
		}
		break;
	}
	case BEDROOM_RIGHT:
	{
		if (!m_riches[1].getClicked())
		{
			m_window.draw(m_riches[1].getBody());
		}
		if (!m_riches[2].getClicked())
		{
			m_window.draw(m_riches[2].getBody());
		}
		break;
	}
	case BATHROOM:
	{
		if (!m_riches[3].getClicked())
		{
			m_window.draw(m_riches[3].getBody());
		}
		break;
	}
	}
}

void Game::renderCovers()
{
	switch (m_room)
	{
	case OUTSIDE:
	{
		m_window.draw(m_covers[0].getBody());
		break;
	}
	case OUTSIDE_NO_DOOR:
		m_window.draw(m_covers[0].getBody());
		break;
	case GREENHOUSE:
	{
		break;
	}
	case HALLWAY_LEFT:
	{
		break;
	}
	case HALLWAY_RIGHT:
	{
		break;
	}
	case KITCHEN:
	{
		m_window.draw(m_covers[1].getSafe());
		m_window.draw(m_covers[1].getCupboard());
		break;
	}
	case LIVING:
	{
		break;
	}
	case BEDROOM_LEFT:
	{
		break;
	}
	case BEDROOM_RIGHT:
	{
		break;
	}
	case BATHROOM:
	{
		break;
	}
	}
}


void Game::renderTools()
{
	switch (m_room)
	{
	case OUTSIDE:
	{
		if (!m_tools[0].getClicked())
		{
			m_window.draw(m_tools[0].getBody());
		}
		break;
	}
	case GREENHOUSE:
	{
		if (!m_tools[2].getClicked())
		{
			m_window.draw(m_tools[2].getBody());
		}
	
		if (!m_tools[3].getClicked())
		{
			m_window.draw(m_tools[3].getBody());
		}

		break;
	}
	case HALLWAY_LEFT:
	{
		break;
	}
	case HALLWAY_RIGHT:
	{
		break;
	}
	case KITCHEN:
	{
		break;
	}
	case LIVING:
	{
		break;
	}
	case BEDROOM_LEFT:
	{
		break;
	}
	case BEDROOM_RIGHT:
	{
		break;
	}
	case BATHROOM:
	{
		break;
	}
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
		m_tools[i].setupSprite(i);
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
	if (!m_bgMusic.openFromFile("ASSETS\\AUDIO\\cynthia.ogg"))
	{
		std::cout << "Music no load"; // error
	}

	m_bgMusic.setVolume(20.f);
	m_bgMusic.setLoop(true);
	m_bgMusic.play();


	m_inventory.loadVoice();

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

	// Gameover Screen Scare Audio
	if (!m_scareBuffer.loadFromFile("ASSETS//AUDIO//final_scream.ogg"))
	{
		std::cout << "Final Scream audio failed to load" << std::endl; // error
	}

	m_scare.setBuffer(m_scareBuffer);
	m_scare.setVolume(20.0f);

	m_roomMusic.setBuffer(m_outsideMusic);

	m_bgMusic.setVolume(20.f);
	m_bgMusic.setLoop(true);
}

/// <summary>
/// Draws objects from Menu class to screen
/// </summary>
void Game::renderScreens()
{
	if (m_screen == MAIN)
	{
		m_window.draw(Menus.getMain());
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
		m_window.clear(sf::Color::Black);
		m_window.draw(Menus.getScare());
	}
	else if (m_screen == WINNING)
	{

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

		if (m_meter.getFilled() == 10)
		{
			m_screen = LOSING;
		}
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
	{
		break;
	}
	case HALLWAY_LEFT:
	{
		break;
	}
	case HALLWAY_RIGHT:
	{
		break;
	}
	case KITCHEN:
	{
		sf::FloatRect cupboard = m_covers[1].getCupboard().getGlobalBounds();
		if (cupboard.contains(m_mousePressed) && !m_covers[1].getClicked())
		{
			m_covers[1].onClick(1);
			clicked = true;
		}
	}
		break;

	case LIVING:
	{
		break;
	}
	case BEDROOM_LEFT:
	{
		break;
	}
	case BEDROOM_RIGHT:
	{
		break;
	}
	case BATHROOM:
	{
		break;
	}
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
		if (key.contains(m_mousePressed) && m_covers[0].getClicked() && !m_tools[0].getClicked())
			// if mouse is on key AND cover is clicked AND key itself is NOT clicked
		{
			m_room = OUTSIDE_NO_DOOR;
			m_tools[0].onClick(0);
			m_inventory.haveKey();
			clicked = true;
		}
		break;
	}
	case OUTSIDE_NO_DOOR:
	{
		sf::FloatRect key = m_tools[0].getBody().getGlobalBounds();
		if (key.contains(m_mousePressed) && m_covers[0].getClicked() && !m_tools[0].getClicked())
			// if mouse is on key AND cover is clicked AND key itself is NOT clicked
		{
			m_room = OUTSIDE_NO_DOOR;
			m_tools[0].onClick(0);
			m_inventory.haveKey();
			clicked = true;
		}
		break;
	}
	case GREENHOUSE:
	{
		sf::FloatRect shovel = m_tools[2].getBody().getGlobalBounds();
		sf::FloatRect crowBar = m_tools[3].getBody().getGlobalBounds();
		if (shovel.contains(m_mousePressed))
		{
			m_tools[2].onClick(2);
			m_inventory.haveShovel();
			m_screen = LOSING;
			clicked = true;
		}
		else if (crowBar.contains(m_mousePressed))
		{
			m_tools[3].onClick(3);
			m_inventory.haveCrowBar();
			clicked = true;
		}

		break;
	}
	case HALLWAY_LEFT:
	{
		break;
	}
	case HALLWAY_RIGHT:
	{
		break;
	}
	case KITCHEN:
	{
		break;
	}
	case LIVING:
	{
		break;
	}
	case BEDROOM_LEFT:
	{
		break;
	}
	case BEDROOM_RIGHT:
	{
		break;
	}
	case BATHROOM:
	{
		break;
	}
	}

	return clicked;
}

bool Game::richesClick()
{
	bool clicked = false;

	switch (m_room)
	{

	case GREENHOUSE:
	{
		sf::FloatRect powrTool = m_riches[4].getBody().getGlobalBounds();
		if (powrTool.contains(m_mousePressed))
		{
			m_riches[4].onClick();
			Hud.itemObtained(5);
			clicked = true;
		}

		break;
	}
	case HALLWAY_LEFT:
	{
		sf::FloatRect saber = m_riches[8].getBody().getGlobalBounds();
		if (saber.contains(m_mousePressed) && !m_riches[8].getClicked())
			// if mouse is on saber AND saber itself is NOT clicked
		{
			m_riches[8].onClick();
			clicked = true;
			Hud.itemObtained(9);
		}
		break;
	}
	case HALLWAY_RIGHT:
	{
		sf::FloatRect coat = m_riches[6].getBody().getGlobalBounds();
		if (coat.contains(m_mousePressed) && !m_riches[6].getClicked())
			// if mouse is on coat AND saber itself is NOT clicked
		{
			m_riches[6].onClick();
			clicked = true;
			Hud.itemObtained(7);
		}
		break;
	}
	case KITCHEN:
	{
		break;
	}
	case LIVING:
	{
		sf::FloatRect vase = m_riches[5].getBody().getGlobalBounds();
		sf::FloatRect cards = m_riches[7].getBody().getGlobalBounds();
		if (vase.contains(m_mousePressed) && !m_riches[5].getClicked())
		{
			m_riches[5].onClick();
			Hud.itemObtained(6);
			clicked = true;
		}
		else if (cards.contains(m_mousePressed) && !m_riches[7].getClicked())
		{
			m_riches[7].onClick();
			Hud.itemObtained(8);
			clicked = true;
		}
		break;
	}
	case BEDROOM_LEFT:
	{
		sf::FloatRect watch = m_riches[0].getBody().getGlobalBounds();
		if (watch.contains(m_mousePressed) && !m_riches[0].getClicked())
		{
			m_riches[0].onClick();
			Hud.itemObtained(1);
			clicked = true;
		}
		break;
	}

	case BEDROOM_RIGHT:
	{
		sf::FloatRect necklace = m_riches[1].getBody().getGlobalBounds();
		if (necklace.contains(m_mousePressed) && !m_riches[1].getClicked())
		{
			m_riches[1].onClick();
			Hud.itemObtained(2);
			clicked = true;
		}
		sf::FloatRect purse = m_riches[2].getBody().getGlobalBounds();
		if (purse.contains(m_mousePressed) && !m_riches[2].getClicked())
		{
			m_riches[2].onClick();
			Hud.itemObtained(3);
			clicked = true;
		}
		break;
	}

	case BATHROOM:
	{
		sf::FloatRect meds = m_riches[3].getBody().getGlobalBounds();
		if (meds.contains(m_mousePressed) && !m_riches[3].getClicked())
		{
			m_riches[3].onClick();
			Hud.itemObtained(4);
			clicked = true;
		}
		break;
	}
	}

	return clicked;
}

void Game::playerMovement()
{
	int facing = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		facing = UP;
		m_player.movement(facing, m_room);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		facing = DOWN;
		m_player.movement(facing, m_room);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		facing = LEFT;
		m_player.movement(facing, m_room);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		facing = RIGHT;
		m_player.movement(facing, m_room);
	}
	else
	{
		m_player.resetTexture();
	}

	m_room = roomCheck(m_room);
	m_player.bounaryCheck(facing, m_room);
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

void Game::menuClick()
{
	sf::FloatRect play = Menus.getMainPlay().getGlobalBounds();
	sf::FloatRect sound = Menus.getMainSound().getGlobalBounds();
	sf::FloatRect help = Menus.getMainHelp().getGlobalBounds();
	sf::FloatRect credits = Menus.getMainCredits().getGlobalBounds();

	if (play.contains(m_mousePressed))
	{
		m_screen = GAMEPLAY;
		m_bgMusic.stop();
		m_roomMusic.play();
	}
	else if (sound.contains(m_mousePressed))
	{
		m_screen = SOUND;
	}
	else if (help.contains(m_mousePressed))
	{
		m_screen = HELP;
	}
	else if (credits.contains(m_mousePressed))
	{
		m_screen = CREDITS;
	}
	else
	{
		m_screen = MAIN;
	}
}

int Game::roomCheck(int t_room)
// function to move player to another room when they move to door
{
	t_room;
	sf::Vector2f leg{ m_player.getLegs().getPosition()};


	// on more room audio, add m_roomBG.setBuffer(''); and m_roomBG.play() for that respective room
	switch (t_room)
	{
	case OUTSIDE:
	{
		if (leg.x < 62 && leg.y < 466 ||
			leg.x < 75 && leg.y < 445 ||
			leg.x < 88 && leg.y < 424 ||
			leg.x < 101 && leg.y < 403)
		{
			t_room = GREENHOUSE;
			m_player.reset(t_room, OUTSIDE);
		}
		break;
	}
	case OUTSIDE_NO_DOOR:
	{
		if (leg.x < 62 && leg.y < 466 ||
			leg.x < 75 && leg.y < 445 ||
			leg.x < 88 && leg.y < 424 ||
			leg.x < 101 && leg.y < 403)
			// walked left to greenhouse door
		{
			t_room = GREENHOUSE;
			m_player.reset(t_room, OUTSIDE_NO_DOOR);
		}
		else if (leg.x > 416 && leg.x < 572
			&& leg.y < 350 && m_tools[0].getClicked())
			// walked up to main door with key in hand
		{
			t_room = HALLWAY_LEFT;
			m_player.reset(t_room, OUTSIDE_NO_DOOR);
		}
		break;
	}
	case GREENHOUSE:
	{
		if ((leg.x > 450 && leg.x < 550) && leg.y > 600 && !m_tools[0].getClicked())
		{
			t_room = OUTSIDE;
			m_player.reset(t_room, GREENHOUSE);
			m_roomMusic.setBuffer(m_outsideMusic);
			m_roomMusic.play();
		}
		else if ((leg.x > 450 && leg.x < 550) && leg.y > 600 && m_tools[0].getClicked())
		{
			t_room = OUTSIDE_NO_DOOR;
			m_player.reset(t_room, GREENHOUSE);
			m_roomMusic.setBuffer(m_outsideMusic);
			m_roomMusic.play();
		}

		break;
	}
	case HALLWAY_LEFT:
	{
		if (leg.x > 1000)
			// walked right to continue in hallway
		{
			t_room = HALLWAY_RIGHT;
			m_player.reset(t_room, HALLWAY_LEFT);
		}
		else if (leg.x < 49 && leg.y < 487 ||
			leg.x < 62 && leg.y < 466 ||
			leg.x < 75 && leg.y < 445 ||
			leg.x < 88 && leg.y < 424 ||
			leg.x < 101 && leg.y < 403)
			//leg.x < 114 && leg.y < 382 )
		{
			t_room = BEDROOM_RIGHT;
			m_player.reset(t_room, HALLWAY_LEFT);
		}
		else if ((leg.x > 450 && leg.x < 550) && leg.y > 600)
		{
			t_room = OUTSIDE_NO_DOOR;
			m_player.reset(t_room, HALLWAY_LEFT);
		}
		break;
	}
	case HALLWAY_RIGHT:
	{
		if (leg.x < 0)
			// walked left to continue in hallway
		{
			t_room = HALLWAY_LEFT;
			m_player.reset(t_room, HALLWAY_RIGHT);
		}
		else if (leg.x > 227 && leg.x < 458 && leg.y < 350)
		{
			t_room = KITCHEN;
			m_player.reset(t_room, HALLWAY_RIGHT);
		}
		else if (leg.y < 487 && leg.y > 382 &&
			(leg.x + LEG_WIDTH > 948 && leg.y < 487 ||
			leg.x + LEG_WIDTH > 935 && leg.y < 466 ||
			leg.x + LEG_WIDTH > 922 && leg.y < 445 ||
			leg.x + LEG_WIDTH > 909 && leg.y < 424 ||
			leg.x + LEG_WIDTH > 896 && leg.y < 403 ||
			leg.x + LEG_WIDTH > 883 && leg.y < 382))
		{
			t_room = LIVING;
			m_player.reset(t_room, HALLWAY_RIGHT);
			std::cout << "!*!*!*!" << std::endl;
			std::cout << "The bounds for this screen is not complete. Kindly assume it is" << std::endl;
			std::cout << "!*!*!*!" << std::endl;
		}
		break;
	}
	case KITCHEN:
	{
		if ((leg.x > 450 && leg.x < 550) && leg.y > 600)
		{
			t_room = HALLWAY_RIGHT;
			m_player.reset(t_room, KITCHEN);
		}
		break;
	}
	case LIVING:
	{
		if ((leg.x > 450 && leg.x < 550) && leg.y > 600)
		{
			t_room = HALLWAY_RIGHT;
			m_player.reset(t_room, LIVING);
		}
		break;
	}
	case BEDROOM_LEFT:
	{
		if (leg.x > 1000)
			// walked right to continue in hallway
		{
			t_room = BEDROOM_RIGHT;
			m_player.reset(t_room, BEDROOM_LEFT);
		}
		else if (leg.x < 62 && leg.y < 466 ||
			leg.x < 75 && leg.y < 445 ||
			leg.x < 88 && leg.y < 424 ||
			leg.x < 101 && leg.y < 403)
			// walked left to greenhouse door
		{
			t_room = BATHROOM;
			m_player.reset(t_room, BEDROOM_LEFT);
		}

		break;
	}

		break;
	case BEDROOM_RIGHT:
	{
		if ((leg.x > 450 && leg.x < 550) && leg.y > 600)
		{
			t_room = HALLWAY_LEFT;
			m_player.reset(t_room, BEDROOM_RIGHT);
		}
		else if (leg.x < 0)
			// walked left to continue in hallway
		{
			t_room = BEDROOM_LEFT;
			m_player.reset(t_room, BEDROOM_RIGHT);
			std::cout << "!*!*!*!" << std::endl;
			std::cout << "The bounds for this screen is not complete. Kindly assume it is" << std::endl;
			std::cout << "!*!*!*!" << std::endl;
		}
		break;
	}
	case BATHROOM:
	{
		if ((leg.x > 750 && leg.x < 850) && leg.y > 600)
		{
			t_room = BEDROOM_LEFT;
			m_player.reset(t_room, BATHROOM);
			std::cout << "!*!*!*!" << std::endl;
			std::cout << "The bounds for this screen is not complete. Kindly assume it is" << std::endl;
			std::cout << "!*!*!*!" << std::endl << std::endl;
		}
		break;
	}

	}

	return t_room;
}

void Game::gameOver()
{
	if (m_time < m_timeTarget)
	{
		m_time += 0.1f;
	}

	if (m_time >= m_timeTarget)
	{
		m_window.close();
	}

	m_scare.play();
	Menus.animateScare();
	//function call for animation or whatever else you want to do
}

void Game::gameWin()
{
	if (m_time < m_timeTarget)
	{
		m_time += 0.1f;
	}

	if (m_time >= m_timeTarget)
	{
		m_window.close();
	}

	//function call for animation or whatever else you want to do
}

