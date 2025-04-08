#include "PipeMiniGame.h"

Pipe::Pipe()
{
	setupSprites();
}

void Pipe::setupSprites()
{
	if (!m_pipeT_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Tpipe.png"))
	{
		std::cout << "Problem loading T pipe image." << std::endl;
	}
	if (!m_pipeL_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Lpipe.png"))
	{
		std::cout << "Problem loading L pipe image." << std::endl;
	}
	if (!m_pipeI_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Ipipe.png"))
	{
		std::cout << "Problem loading I pipe image." << std::endl;
	}
	if (!m_pipeD_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Dpipe.png"))
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

	m_pipeT.setTexture(m_pipeT_Texture);
	m_pipeL.setTexture(m_pipeL_Texture);
	m_pipeI.setTexture(m_pipeI_Texture);
	m_pipeD.setTexture(m_pipeD_Texture);
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

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_tile.setPosition(CELLSIZE * j, CELLSIZE * i);
			t_window.draw(m_tile);

			if (m_grid[i][j] == 1101 || m_grid[i][j] == 1110 || m_grid[i][j] == 0111 || m_grid[i][j] == 1011)
			{
				m_pipeT.setPosition(CELLSIZE * j, CELLSIZE * i);
				t_window.draw(m_pipeT);
			}

			if (m_grid[i][j] == 1001 || m_grid[i][j] == 1100 || m_grid[i][j] == 0110 || m_grid[i][j] == 0011)
			{
				m_pipeL.setPosition(CELLSIZE * j, CELLSIZE * i);
				t_window.draw(m_pipeL);
			}

			if (m_grid[i][j] == 0101 || m_grid[i][j] == 1010)
			{
				m_pipeI.setPosition(CELLSIZE * j, CELLSIZE * i);
				t_window.draw(m_pipeI);
			}

			if (m_grid[i][j] == 1000 || m_grid[i][j] == 0100 || m_grid[i][j] == 0010 || m_grid[i][j] == 0001)
			{
				m_pipeD.setPosition(CELLSIZE * j, CELLSIZE * i);
				t_window.draw(m_pipeD);
			}

			if (m_grid[i][j] == 1999)
			{
				m_pipeS.setPosition(CELLSIZE * j, CELLSIZE * i);
				t_window.draw(m_pipeS);
			}
		}
	}

	t_window.display();
}


