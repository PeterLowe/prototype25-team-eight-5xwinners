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

	m_sprite.setScale(0.7f, 0.7f);
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

	if (t_facing == LEFT)
	{
		pos.x = pos.x - m_speed;
	}
	if (t_facing == RIGHT)
	{
		pos.x = pos.x + m_speed;
	}
	if (t_facing == UP)
	{
		pos.y = pos.y - m_speed;
	}
	if (t_facing == DOWN)
	{
		pos.y = pos.y + m_speed;
	}

	m_sprite.setPosition(pos);
}

void Player::setPoosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
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

	if (legY < 350)
		// Keeping player from going above floor
	{
		leg.y += 5;
		body.y += 5;

	}
	else if (legY > 600)
		// Keeping player from going below invis floor
	{
		leg.y -= 5;
		body.y -= 5;
	}

	if (legX < 0 + LEG_WIDTH / 2)
		// keeping player from going out of left side of screen
	{
		leg.x += 5;
		body.x += 5;
	}
	else if (legX > SCREEN_WIDTH - LEG_WIDTH / 2)
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


void Player::leftDiaBounds(float& t_legX, float& t_legY, int t_facing)
{
	if (t_legX < 130 && t_legY > 340 && t_legY < 530)
	{
		if (t_legX < 23 && t_legY < 530 ||
			t_legX < 36 && t_legY < 508 ||
			t_legX < 49 && t_legY < 487 ||
			t_legX < 62 && t_legY < 466 ||
			t_legX < 75 && t_legY < 445 ||
			t_legX < 88 && t_legY < 424 ||
			t_legX < 101 && t_legY < 403 ||
			t_legX < 114 && t_legY < 382 ||
			t_legX < 127 && t_legY < 361 ||
			t_legX < 130 && t_legY < 340)
		{
			if (t_facing == LEFT)
				// if player walks to dia facing left, we push them down
			{
				t_legY += 10;	// 10 and not 5 to deal with hypotenuse being longer
			}
			else if (t_facing == UP)
				// if player walks to dia facing up, we push them right
			{
				t_legX += 5;
			}
		}
	}


}


void Player::rightDiaBounds(sf::Vector2f& t_leg, sf::Vector2f& t_body, int t_facing)
{
	if (t_leg.x > 870 && t_leg.y > 340 && t_leg.y < 530)
	{
		if (t_legX > 978 && t_legY < 530 ||
			t_legX > 966 && t_legY < 508 ||
			t_legX > 954 && t_legY < 487 ||
			t_legX > 942 && t_legY < 466 ||
			t_legX > 930 && t_legY < 445 ||
			t_legX > 918 && t_legY < 424 ||
			t_legX > 906 && t_legY < 403 ||
			t_legX > 894 && t_legY < 382 ||
			t_legX > 882 && t_legY < 361 ||
			t_legX > 870 && t_legY < 340)
		{
			if (t_facing == RIGHT)
				// if player walks to dia facing left, we push them down
			{
				t_legY += 10;	// 10 and not 5 to deal with hypotenuse being longer
			}
			else if (t_facing == UP)
				// if player walks to dia facing up, we push them right
			{
				t_legX -= 5;
			}
		}
	}


}



