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

void Player::movement(int t_facing)
//moves the player
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
{
	return m_sprite.getPosition();
}

sf::Sprite Player::getBody()
{
	return m_sprite;
}


void Player::bounaryCheck(int t_facing)
//stops player from moving out the gameplay bounds
// Arceus bless me in what I am to do
{
	sf::Vector2f leg{ m_legsRect.getPosition() };
	sf::Vector2f body{ m_sprite.getPosition() };

	if (leg.y < 350)
		// Keeping player from going above floor
	{
		leg.y += 5;
		body.y += 5;

	}
	else if (leg.y > 600)
		// Keeping player from going below invis floor
	{
		leg.y -= 5;
		body.y -= 5;
	}

	if (leg.x < 0 + LEG_WIDTH / 2)
		// keeping player from going out of left side of screen
	{
		leg.x += 5;
		body.x += 5;
	}
	else if (leg.x > SCREEN_WIDTH - (LEG_WIDTH * 1.5))
		// keeping player from going out of right side of screen
	{
		leg.x -= 5;
		body.x -= 5;
	}



	leftDiaBounds(leg, body, t_facing);	
	// passing updated coords to diagonal bound check BEFORE actually updating the player and THEN changing back
	rightDiaBounds(leg, body, t_facing);



	m_legsRect.setPosition(leg);
	m_sprite.setPosition(body);


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


