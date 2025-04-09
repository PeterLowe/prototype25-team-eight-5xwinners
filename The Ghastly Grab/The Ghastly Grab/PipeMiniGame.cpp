#include "PipeMiniGame.h"

Pipe::Pipe()
{
	setupSprites();
}

void Pipe::setupSprites()
{
	if (!m_pipeT0_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Tpipe0.png"))
	{
		std::cout << "Problem loading T pipe image." << std::endl;
	}
	if (!m_pipeL0_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Lpipe0.png"))
	{
		std::cout << "Problem loading L pipe image." << std::endl;
	}
	if (!m_pipeI0_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Ipipe0.png"))
	{
		std::cout << "Problem loading I pipe image." << std::endl;
	}
	if (!m_pipeD0_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Dpipe0.png"))
	{
		std::cout << "Problem loading Destination pipe image." << std::endl;
	}
	if (!m_pipeS_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Spipe.png"))
	{
		std::cout << "Problem loading Source pipe image." << std::endl;
	}
	if (!m_tile_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Tile.png"))
	{
		std::cout << "Problem loading tile image." << std::endl;
	}

	m_pipeT0.setTexture(m_pipeT0_Texture);
	m_pipeT0.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_pipeT0.setOrigin(32, 32);
	m_pipeL0.setTexture(m_pipeL0_Texture);
	m_pipeL0.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_pipeI0.setTexture(m_pipeI0_Texture);
	m_pipeI0.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_pipeD0.setTexture(m_pipeD0_Texture);
	m_pipeD0.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_pipeS.setTexture(m_pipeS_Texture);
	m_tile.setTexture(m_tile_Texture);
	
	m_player.setSize(sf::Vector2f(64.0f, 64.0f));
	m_player.setOutlineColor(sf::Color::White);
	m_player.setFillColor(sf::Color::Transparent);
	m_player.setOutlineThickness(-2.0f);
}

void Pipe::render(sf::RenderWindow& t_window)
{
	t_window.clear(sf::Color::Black);

	for (int i = 0; i < GRIDSIZE; i++)
	{
		for (int j = 0; j < GRIDSIZE; j++)
		{
			m_tile.setPosition(CELLSIZE * j, CELLSIZE * i);
			t_window.draw(m_tile);

			//if T pipe
			if (m_grid[i][j] == 1101 || m_grid[i][j] == 1110 || m_grid[i][j] == 0111 || m_grid[i][j] == 1011)
			{
				if (m_grid[i][j] == 1101)
				{
					m_pipeT0.setPosition(CELLSIZE * j+32, CELLSIZE * i+32);
					m_pipeT0.setRotation(0.0f);
					t_window.draw(m_pipeT0);
				}
				else if (m_grid[i][j] == 1110)
				{
					m_pipeT0.setPosition(CELLSIZE * j+32, CELLSIZE * i+32);
					m_pipeT0.setRotation(90.0f);
					t_window.draw(m_pipeT0);
				}
				else if (m_grid[i][j] == 0111)
				{
					m_pipeT0.setPosition(CELLSIZE * j+32, CELLSIZE * i+32);
					m_pipeT0.setRotation(180.0f);
					t_window.draw(m_pipeT0);
				}
				else if (m_grid[i][j] == 1011)
				{
					m_pipeT0.setPosition(CELLSIZE * j+32, CELLSIZE * i+32);
					m_pipeT0.setRotation(270.0f);
					t_window.draw(m_pipeT0);
				}
			}

			//if L pipe
			if (m_grid[i][j] == 1001 || m_grid[i][j] == 1100 || m_grid[i][j] == 0110 || m_grid[i][j] == 0011)
			{
				if (m_grid[i][j] == 1001)
				{
					m_pipeL0.setPosition(CELLSIZE * j, CELLSIZE * i);
					t_window.draw(m_pipeL0);
				}
				else if (m_grid[i][j] == 1100)
				{
					m_pipeL90.setPosition(CELLSIZE * j, CELLSIZE * i);
					t_window.draw(m_pipeL90);
				}
				else if (m_grid[i][j] == 0110)
				{
					m_pipeL180.setPosition(CELLSIZE * j, CELLSIZE * i);
					t_window.draw(m_pipeL180);
				}
				else if (m_grid[i][j] == 0011)
				{
					m_pipeL270.setPosition(CELLSIZE * j, CELLSIZE * i);
					t_window.draw(m_pipeL270);
				}
			}

			//if I pipe
			if (m_grid[i][j] == 0101 || m_grid[i][j] == 1010)
			{
				if (m_grid[i][j] == 0101)
				{
					m_pipeI0.setPosition(CELLSIZE * j, CELLSIZE * i);
					t_window.draw(m_pipeI0);
				}
				else if (m_grid[i][j] == 1010)
				{
					m_pipeI90.setPosition(CELLSIZE * j, CELLSIZE * i);
					t_window.draw(m_pipeI90);
				}
			}

			//if Destination pipe
			if (m_grid[i][j] == 1000 || m_grid[i][j] == 0100 || m_grid[i][j] == 0010 || m_grid[i][j] == 0001)
			{
				if (m_grid[i][j] == 1000)
				{
					m_pipeD0.setPosition(CELLSIZE * j, CELLSIZE * i);
					t_window.draw(m_pipeD0);
				}
				if (m_grid[i][j] == 0100)
				{
					m_pipeD90.setPosition(CELLSIZE * j, CELLSIZE * i);
					t_window.draw(m_pipeD90);
				}
				if (m_grid[i][j] == 0010)
				{
					m_pipeD90.setPosition(CELLSIZE * j, CELLSIZE * i);
					t_window.draw(m_pipeD90);
				}
				if (m_grid[i][j] == 0001)
				{
					m_pipeD270.setPosition(CELLSIZE * j, CELLSIZE * i);
					t_window.draw(m_pipeD270);
				}
			}

			//if Source pipe
			if (m_grid[i][j] == 1999)
			{
				m_pipeS.setPosition(CELLSIZE * j, CELLSIZE * i);
				t_window.draw(m_pipeS);
			}
		}
	}

	t_window.display();
}

void Pipe::update()
{

}

void Pipe::rotate(sf::Vector2f t_pos)
{

}

