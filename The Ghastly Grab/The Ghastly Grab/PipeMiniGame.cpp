#include "PipeMiniGame.h"

Pipe::Pipe()
{
	setupSprites();
}

void Pipe::setupSprites()
{
	if (!m_pipeT_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Tpipe0.png"))
	{
		std::cout << "Problem loading T pipe image." << std::endl;
	}
	if (!m_pipeL_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Lpipe0.png"))
	{
		std::cout << "Problem loading L pipe image." << std::endl;
	}
	if (!m_pipeI_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Ipipe0.png"))
	{
		std::cout << "Problem loading I pipe image." << std::endl;
	}
	if (!m_pipeD_Texture.loadFromFile("ASSETS\\IMAGES\\pipe\\Dpipe0.png"))
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
	m_pipeT.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_pipeT.setOrigin(32, 32);
	m_pipeL.setTexture(m_pipeL_Texture);
	m_pipeL.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_pipeL.setOrigin(32, 32);
	m_pipeI.setTexture(m_pipeI_Texture);
	m_pipeI.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_pipeI.setOrigin(32, 32);
	m_pipeD.setTexture(m_pipeD_Texture);
	m_pipeD.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_pipeD.setOrigin(32, 32);
	m_pipeS.setTexture(m_pipeS_Texture);
	m_tile.setTexture(m_tile_Texture);

	m_player.setSize(sf::Vector2f(64.0f, 64.0f));
	m_player.setPosition(sf::Vector2f(0.0f, 0.0f));
	m_player.setFillColor(sf::Color::Transparent);
	m_player.setOutlineColor(sf::Color(200,200,220, 255));
	m_player.setOutlineThickness(-6.0f);
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
			if (m_grid[i][j] == 51101 || m_grid[i][j] == 51110 || m_grid[i][j] == 50111 || m_grid[i][j] == 51011)
			{
				if (m_grid[i][j] == 51101)
				{
					m_pipeT.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeT.setRotation(0.0f);
					t_window.draw(m_pipeT);
				}
				else if (m_grid[i][j] == 51110)
				{
					m_pipeT.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeT.setRotation(90.0f);
					t_window.draw(m_pipeT);
				}
				else if (m_grid[i][j] == 50111)
				{
					m_pipeT.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeT.setRotation(180.0f);
					t_window.draw(m_pipeT);
				}
				else if (m_grid[i][j] == 51011)
				{
					m_pipeT.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeT.setRotation(270.0f);
					t_window.draw(m_pipeT);
				}
			}

			//if L pipe
			if (m_grid[i][j] == 51001 || m_grid[i][j] == 51100 || m_grid[i][j] == 50110 || m_grid[i][j] == 50011)
			{
				if (m_grid[i][j] == 51001)
				{
					m_pipeL.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeL.setRotation(0.0f);
					t_window.draw(m_pipeL);
				}
				else if (m_grid[i][j] == 51100)
				{
					m_pipeL.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeL.setRotation(90.0f);
					t_window.draw(m_pipeL);
				}
				else if (m_grid[i][j] == 50110)
				{
					m_pipeL.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeL.setRotation(180.0f);
					t_window.draw(m_pipeL);
				}
				else if (m_grid[i][j] == 50011)
				{
					m_pipeL.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeL.setRotation(270.0f);
					t_window.draw(m_pipeL);
				}
			}

			//if I pipe
			if (m_grid[i][j] == 50101 || m_grid[i][j] == 51010)
			{
				if (m_grid[i][j] == 50101)
				{
					m_pipeI.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeI.setRotation(0.0f);
					t_window.draw(m_pipeI);
				}
				else if (m_grid[i][j] == 51010)
				{
					m_pipeI.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeI.setRotation(90.0f);
					t_window.draw(m_pipeI);
				}
			}

			//if Destination pipe
			if (m_grid[i][j] == 51000 || m_grid[i][j] == 50100 || m_grid[i][j] == 50010 || m_grid[i][j] == 50001)
			{
				if (m_grid[i][j] == 51000)
				{
					m_pipeD.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeD.setRotation(0.0f);
					t_window.draw(m_pipeD);
				}
				if (m_grid[i][j] == 50100)
				{
					m_pipeD.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeD.setRotation(90.0f);
					t_window.draw(m_pipeD);
				}
				if (m_grid[i][j] == 50010)
				{
					m_pipeD.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeD.setRotation(180.0f);
					t_window.draw(m_pipeD);
				}
				if (m_grid[i][j] == 50001)
				{
					m_pipeD.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					m_pipeD.setRotation(270.0f);
					t_window.draw(m_pipeD);
				}
			}

			//if Source pipe
			if (m_grid[i][j] == 61999)
			{
				m_pipeS.setPosition(CELLSIZE * j, CELLSIZE * i);
				t_window.draw(m_pipeS);
			}
		}
	}

	t_window.draw(m_player);

	t_window.display();
}

void Pipe::update()
{

}

void Pipe::rotate(sf::Vector2f t_pos)
{
	int posx = t_pos.x / CELLSIZE;
	int posy = t_pos.y / CELLSIZE;

	for (int i = 0; i < GRIDSIZE; i++)
	{
		for (int j = 0; j < GRIDSIZE; j++)
		{
			if (m_grid[posy][posx] != 61999)
			{
				//if T pipe
				if (m_grid[posy][posx] == 51101 || m_grid[posy][posx] == 51110 || m_grid[posy][posx] == 50111 || m_grid[posy][posx] == 51011)
				{
					if (m_grid[posy][posx] == 51101)
					{
						m_grid[posy][posx] = 51110;
					}
					else if (m_grid[posy][posx] == 51110)
					{
						m_grid[posy][posx] = 50111;
					}
					else if (m_grid[posy][posx] == 50111)
					{
						m_grid[posy][posx] = 51011;
					}
					else if (m_grid[posy][posx] == 51011)
					{
						m_grid[posy][posx] = 51101;
					}
				}

				//if L pipe
				else if (m_grid[posy][posx] == 51001 || m_grid[posy][posx] == 51100 || m_grid[posy][posx] == 50110 || m_grid[posy][posx] == 50011)
				{
					if (m_grid[posy][posx] == 51001)
					{
						m_grid[posy][posx] = 51100;
					}
					else if (m_grid[posy][posx] == 51100)
					{
						m_grid[posy][posx] = 50110;
					}
					else if (m_grid[posy][posx] == 50110)
					{
						m_grid[posy][posx] = 50011;
					}
					else if (m_grid[posy][posx] == 50011)
					{
						m_grid[posy][posx] = 51001;
					}
				}

				//if I pipe
				else if (m_grid[posy][posx] == 50101 || m_grid[posy][posx] == 51010)
				{
					if (m_grid[posy][posx] == 50101)
					{
						m_grid[posy][posx] = 51010;
					}
					else if (m_grid[posy][posx] == 51010)
					{
						m_grid[posy][posx] = 50101;
					}
				}

				//if Destination pipe
				else if (m_grid[posy][posx] == 51000 || m_grid[posy][posx] == 50100 || m_grid[posy][posx] == 50010 || m_grid[posy][posx] == 50001)
				{
					if (m_grid[posy][posx] == 51000)
					{
						m_grid[posy][posx] = 50100;
					}
					else if (m_grid[posy][posx] == 50100)
					{
						m_grid[posy][posx] = 50010;
					}
					else if (m_grid[posy][posx] == 50010)
					{
						m_grid[posy][posx] = 50001;
					}
					else if (m_grid[posy][posx] == 50001)
					{
						m_grid[posy][posx] = 51000;
					}
				}
			}
		}
	}
}

/*void Pipe::processMouse(sf::Event t_event)
{
	m_clickPos.x = static_cast<float>(t_event.mouseButton.x);
	m_clickPos.y = static_cast<float>(t_event.mouseButton.y);
}*/

void Pipe::dothing()
{
	std::cout << m_grid[0][3];
}

