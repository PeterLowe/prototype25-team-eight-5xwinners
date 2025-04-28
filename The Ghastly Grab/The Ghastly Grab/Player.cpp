//author team_8 - [5xWinners]

#include "Player.h"

Player::Player()
{
	loadImage();
}

void Player::loadImage()
//loads player sprite from files
{
	if (!m_texture.loadFromFile("ASSETS/IMAGES/PLAYER.png"))
	{
		std::cout << "error with player image file";
	}

	if (!m_textureUp.loadFromFile("ASSETS/IMAGES/PLAYER_UP.png"))
	{
		std::cout << "Error with the player_UP image file";
	}

	if (!m_textureRight.loadFromFile("ASSETS/IMAGES/PLAYER_RIGHT.png"))
	{
		std::cout << "Error with the player_RIGHT image file";
	}

	if (!m_textureLeft.loadFromFile("ASSETS/IMAGES/PLAYER_LEFT.png"))
	{
		std::cout << "Error with the player_LEFT image file";
	}

	m_sprite.setScale(2.625f, 3.390625f);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition({ SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 - 100});

	// Rect for legs
	m_legsRect.setOrigin(LEG_WIDTH / 2, LEG_HEIGHT / 2);
	m_legsRect.setPosition((SCREEN_WIDTH / 2) + LEFT_TO_LEG, (SCREEN_HEIGHT / 2) + UP_TO_LEG - 100);
}

void Player::movement(int t_facing, int t_room)
// moves player and redirects boundary check based on respective room
{
	sf::Vector2f pos(m_sprite.getPosition());
	sf::Vector2f legPos(m_legsRect.getPosition());

	if (t_facing == LEFT)
	{
		m_sprite.setTexture(m_textureLeft);
		moveSide();
		pos.x = pos.x - m_speed;
		legPos.x -= m_speed;
	}
	if (t_facing == RIGHT)
	{
		m_sprite.setTexture(m_textureRight);
		moveSide();
		pos.x = pos.x + m_speed;
		legPos.x += m_speed;
	}
	if (t_facing == UP)
	{
		moveUp();
		pos.y = pos.y - m_speed;
		legPos.y -= m_speed;
	}
	if (t_facing == DOWN)
	{
		moveUp();
		pos.y = pos.y + m_speed;
		legPos.y += m_speed;
	}

	m_sprite.setPosition(pos);
	m_legsRect.setPosition(legPos);
}

sf::Vector2f Player::getPosition()
// return position of player
{
	return m_sprite.getPosition();
}

sf::Sprite Player::getBody()
// return the sprite of player
{
	return m_sprite;
}

sf::RectangleShape Player::getLegs()
{
	return m_legsRect;
}

void Player::reset(int t_room, int t_oldRoom)
{
	switch (t_room)
	{
	case OUTSIDE:
	{
		break;
	}
	case OUTSIDE_NO_DOOR:
	{
		break;
	}
	case GREENHOUSE:
	{
		m_sprite.setPosition(SCREEN_WIDTH / 2, 350);
		m_legsRect.setPosition((SCREEN_WIDTH / 2) + LEFT_TO_LEG, 350 + UP_TO_LEG);
		break;
	}

	case HALLWAY_LEFT:
	{
		if (t_oldRoom == OUTSIDE || t_oldRoom == OUTSIDE_NO_DOOR)
		{
			m_sprite.setPosition(SCREEN_WIDTH / 2, 350);
			m_legsRect.setPosition((SCREEN_WIDTH / 2) + LEFT_TO_LEG, 350 + UP_TO_LEG);
			break;
		}
		else if (t_oldRoom == HALLWAY_RIGHT)
		{
			m_sprite.setPosition(SCREEN_WIDTH - 50 , 250);
			m_legsRect.setPosition(SCREEN_WIDTH - 50 + LEFT_TO_LEG, 250 + UP_TO_LEG);
			break;
		}

	}
	case HALLWAY_RIGHT:
	{
		if (t_oldRoom == HALLWAY_LEFT)
		{
			m_sprite.setPosition(10, 250);
			m_legsRect.setPosition(10+LEFT_TO_LEG, 250 + UP_TO_LEG);
		}

		break;

	}
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


void Player::bounaryCheck(int t_facing, int t_room)
//stops player from moving out the gameplay bounds specific to the room they are in
// This function is blessed by Arceus
{
	sf::Vector2f leg{ m_legsRect.getPosition() };
	sf::Vector2f body{ m_sprite.getPosition() };

	switch (t_room)
	{
	case OUTSIDE:
	{
		outsideBounds(t_facing, leg, body);
		break;
	}
	case OUTSIDE_NO_DOOR:
	{
		outsideBounds(t_facing, leg, body);
		break;
	}
	case GREENHOUSE:
		break;
	case HALLWAY_LEFT:
		leftHallBounds(t_facing, leg, body);
		break;
	case HALLWAY_RIGHT:
		rightHallBounds(t_facing, leg, body);
		break;
	case KITCHEN:
	{
		kitchenBounds(t_facing, leg, body);
		break;
	}
	case LIVING:
		break;
	case BEDROOM_LEFT:
		break;
	case BEDROOM_RIGHT:
		break;
	case BATHROOM:
		break;
	}

	m_sprite.setPosition(body);
	m_legsRect.setPosition(leg);
}

void Player::outsideBounds(int t_facing, sf::Vector2f &t_leg, sf::Vector2f &t_body)	
// bound check specific to outside
{

	if (t_leg.y < 350)
		// Keeping player from going above floor
	{
		t_leg.y += 5;
		t_body.y += 5;

	}
	else if (t_leg.y > 600)
		// Keeping player from going below invis floor
	{
		t_leg.y -= 5;
		t_body.y -= 5;
	}

	if (t_leg.x < 0 + LEG_WIDTH / 2)
		// keeping player from going out of left side of screen
	{
		t_leg.x += 5;
		t_body.x += 5;
	}
	else if (t_leg.x > SCREEN_WIDTH - (LEG_WIDTH * 1.5))
		// keeping player from going out of right side of screen
	{
		t_leg.x -= 5;
		t_body.x -= 5;
	}

	leftDiaBounds(t_leg, t_body, t_facing);
	// passing updated coords to diagonal bound check BEFORE actually updating the player and THEN changing back
}

void Player::rightHallBounds(int t_facing, sf::Vector2f& t_leg, sf::Vector2f& t_body)
{
	if (t_leg.x > 700 && t_leg.x < 800)
		// Keeping player from going into coat stand
	{
		if (t_leg.y < 387)
		{
			t_leg.y += 5;
			t_body.y += 5;
		}
	}

	if (t_leg.y < 350)
		// Keeping player from going above floor
	{
		t_leg.y += 5;
		t_body.y += 5;

	}
	else if (t_leg.y > 600)
		// Keeping player from going below invis floor
	{
		t_leg.y -= 5;
		t_body.y -= 5;
	}

	if (t_leg.x > SCREEN_WIDTH - (LEG_WIDTH * 1.5))
		// keeping player from going out of right side of screen
	{
		t_leg.x -= 5;
		t_body.x -= 5;
	}

	rightDiaBounds(t_leg, t_body, t_facing);
	// passing updated coords to diagonal bound check BEFORE actually updating the player and THEN changing back
}

void Player::leftHallBounds(int t_facing, sf::Vector2f& t_leg, sf::Vector2f& t_body)
{
	if (t_leg.x > 460 && t_leg.x < 820)
		// Keeping player from going into cupboard
	{
		if (t_leg.y < 370)
		{
			t_leg.y += 5;
			t_body.y += 5;
		}
	}

	if (t_leg.y < 350)
		// Keeping player from going above floor
	{
		t_leg.y += 5;
		t_body.y += 5;

	}
	else if (t_leg.y > 600)
		// Keeping player from going below invis floor
	{
		t_leg.y -= 5;
		t_body.y -= 5;
	}

	if (t_leg.x < 0 + LEG_WIDTH / 2)
		// keeping player from going out of left side of screen
	{
		t_leg.x += 5;
		t_body.x += 5;
	}

	leftDiaBounds(t_leg, t_body, t_facing);
	// passing updated coords to diagonal bound check BEFORE actually updating the player and THEN changing back
}

void Player::kitchenBounds(int t_facing, sf::Vector2f& t_leg, sf::Vector2f& t_body)
// bound check specific to outside
{

	if (t_leg.y < 415)
		// Keeping player from going above floor
	{
		t_leg.y += 5;
		t_body.y += 5;

	}
	else if (t_leg.y > 600)
		// Keeping player from going below invis floor
	{
		t_leg.y -= 5;
		t_body.y -= 5;
	}

	if (t_leg.x < 0 + LEG_WIDTH / 2)
		// keeping player from going out of left side of screen
	{
		t_leg.x += 5;
		t_body.x += 5;
	}
	else if (t_leg.x > SCREEN_WIDTH - (LEG_WIDTH * 2))
		// keeping player from going out of right side of screen
	{
		t_leg.x -= 5;
		t_body.x -= 5;
	}

	leftDiaBounds(t_leg, t_body, t_facing);
	rightDiaBounds(t_leg, t_body, t_facing);
	// passing updated coords to diagonal bound check BEFORE actually updating the player and THEN changing back
}


void Player::leftDiaBounds(sf::Vector2f& t_leg, sf::Vector2f& t_body, int t_facing)
{
	if (t_leg.x < 130 && t_leg.y > 340 && t_leg.y < 530)
	{
		if (t_leg.x < 23 && t_leg.y < 530 ||
			t_leg.x < 36 && t_leg.y < 508 ||
			t_leg.x < 49 && t_leg.y < 487 ||
			t_leg.x < 62 && t_leg.y < 466 ||
			t_leg.x < 75 && t_leg.y < 445 ||
			t_leg.x < 88 && t_leg.y < 424 ||
			t_leg.x < 101 && t_leg.y < 403 ||
			t_leg.x < 114 && t_leg.y < 382 ||
			t_leg.x < 127 && t_leg.y < 361 ||
			t_leg.x < 130 && t_leg.y < 340)
		{
			if (t_facing == LEFT)
				// if player walks to dia facing left, we push them down
			{
				t_leg.y += 10;	// 10 and not 5 to deal with hypotenuse being longer
				t_body.y += 10;
			}
			else if (t_facing == UP)
				// if player walks to dia facing up, we push them right
			{
				t_leg.x += 5;
				t_body.x += 5;
			}
		}
	}
}


void Player::rightDiaBounds(sf::Vector2f& t_leg, sf::Vector2f& t_body, int t_facing)
{
	if (t_leg.x > 850 && t_leg.y > 340 && t_leg.y < 530)
	{
		if (t_leg.x + LEG_WIDTH > 974 && t_leg.y < 530 ||
			t_leg.x + LEG_WIDTH > 961 && t_leg.y < 508 ||
			t_leg.x + LEG_WIDTH > 948 && t_leg.y < 487 ||
			t_leg.x + LEG_WIDTH > 935 && t_leg.y < 466 ||
			t_leg.x + LEG_WIDTH > 922 && t_leg.y < 445 ||
			t_leg.x + LEG_WIDTH > 909 && t_leg.y < 424 ||
			t_leg.x + LEG_WIDTH > 896 && t_leg.y < 403 ||
			t_leg.x + LEG_WIDTH > 883 && t_leg.y < 382	)
		{
			if (t_facing == RIGHT)
				// if player walks to dia facing left, we push them down
			{
				t_leg.y += 10;	// 10 and not 5 to deal with hypotenuse being longer
				t_body.y += 10;
			}
			else if (t_facing == UP)
				// if player walks to dia facing up, we push them right
			{
				t_leg.x -= 5;
				t_body.x -= 5;
			}
		}
	}

}


void Player::resetTexture()
{
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect({ sf::IntRect(0,0,32,64) });
}



void Player::moveUp()
// function to animate player moving up
{
	m_sprite.setTexture(m_textureUp);
	if (m_frame < 8)
	{
		m_sprite.setTextureRect({ sf::IntRect(0,0,32,64) });
	}
	else if (m_frame < 16)
	{
		m_sprite.setTextureRect({ sf::IntRect(32,0,32,64) });
	}
	else if (m_frame < 24)
	{
		m_sprite.setTextureRect({ sf::IntRect(64,0,32,64) });
	}
	else
	{
		m_sprite.setTextureRect({ sf::IntRect(96,0,32,64) });
		if (m_frame > 32)
		{
			m_frame = 0;
		}
	}

	m_frame++;
}

void Player::moveSide()
// function to animate player moving sideways
{
	if (m_frame < 8)
	{
		m_sprite.setTextureRect({ sf::IntRect(0,0,32,64) });
	}
	else if (m_frame < 16)
	{
		m_sprite.setTextureRect({ sf::IntRect(32,0,32,64) });
	}
	else if (m_frame < 24)
	{
		m_sprite.setTextureRect({ sf::IntRect(64,0,32,64) });
	}
	else if (m_frame < 32)
	{
		m_sprite.setTextureRect({ sf::IntRect(96,0,32,64) });
	}
	else if (m_frame < 40)
	{
		m_sprite.setTextureRect({ sf::IntRect(128,0,32,64) });
	}
	else if (m_frame < 48)
	{
		m_sprite.setTextureRect({ sf::IntRect(160,0,32,64) });
	}
	else if (m_frame < 56)
	{
		m_sprite.setTextureRect({ sf::IntRect(192,0,32,64) });
	}
	else
	{
		m_sprite.setTextureRect({ sf::IntRect(224,0,32,64) });
		if (m_frame > 64)
		{
			m_frame = 0;
		}
	}

	m_frame++;
}





