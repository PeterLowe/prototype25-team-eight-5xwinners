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

	/*m_player.setSize(sf::Vector2f(64.0f, 64.0f));
	m_player.setPosition(sf::Vector2f(0.0f, 0.0f));
	m_player.setFillColor(sf::Color::Transparent);
	m_player.setOutlineColor(sf::Color(200,200,220, 255));
	m_player.setOutlineThickness(-6.0f);*/
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

			int pipe = m_grid[i][j];		//I don't know why I didn't think of doing this much sooner instead of writing out m_grid[i][j] a thousand times
			bool found = false;				//if the pipe was found we don't need to keep looking for it where we won't find it

			//first loop checks for T pipes
			for (int p = 0; p < 8; p++)
			{
				if (pipe == TPIPE[p])		//if this tile contains a T pipe...
				{
					switch (pipe)			//set the rotation
					{
					case 51101:
					case 61101:
						m_pipeT.setRotation(0);
						break;
					case 51110:
					case 61110:
						m_pipeT.setRotation(90);
						break;
					case 50111:
					case 60111:
						m_pipeT.setRotation(180);
						break;
					case 51011:
					case 61011:
						m_pipeT.setRotation(270);
						break;
					}

					//update the sprite/texture depending on if the tile contains water or not
					if (pipe / 10000 == 6)
					{
						m_pipeT.setTextureRect(sf::IntRect(64, 0, 64, 64));
					}
					else
					{
						m_pipeT.setTextureRect(sf::IntRect(0, 0, 64, 64));
					}

					//set its position and draw it
					m_pipeT.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
					t_window.draw(m_pipeT);

					found = true;
					break;
				}
			}

			if (!found)
			{
				//this loop checks for L pipes
				for (int p = 0; p < 8; p++)
				{
					if (pipe == LPIPE[p])
					{
						switch (pipe)
						{
						case 51001:
						case 61001:
							m_pipeL.setRotation(0);
							break;
						case 51100:
						case 61100:
							m_pipeL.setRotation(90);
							break;
						case 50110:
						case 60110:
							m_pipeL.setRotation(180);
							break;
						case 50011:
						case 60011:
							m_pipeL.setRotation(270);
							break;
						}

						if (pipe / 10000 == 6)
						{
							m_pipeL.setTextureRect(sf::IntRect(64, 0, 64, 64));
						}
						else
						{
							m_pipeL.setTextureRect(sf::IntRect(0, 0, 64, 64));
						}

						m_pipeL.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
						t_window.draw(m_pipeL);

						found = true;
						break;
					}
				}
			}

			if (!found)
			{
				//this loop checks for I pipes
				for (int p = 0; p < 4; p++)
				{
					if (pipe == IPIPE[p])
					{
						switch (pipe)
						{
						case 51010:
						case 61010:
							m_pipeI.setRotation(0);
							break;
						case 50101:
						case 60101:
							m_pipeI.setRotation(90);
							break;
						}

						if (pipe / 10000 == 6)
						{
							m_pipeI.setTextureRect(sf::IntRect(64, 0, 64, 64));
						}
						else
						{
							m_pipeI.setTextureRect(sf::IntRect(0, 0, 64, 64));
						}

						m_pipeI.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
						t_window.draw(m_pipeI);

						found = true;
						break;
					}
				}
			}

			if (!found)
			{
				//this loop checks for D pipes
				for (int p = 0; p < 8; p++)
				{
					if (pipe == DPIPE[p])
					{
						switch (pipe)
						{
						case 51000:
						case 61000:
							m_pipeD.setRotation(0);
							break;
						case 50100:
						case 60100:
							m_pipeD.setRotation(90);
							break;
						case 50010:
						case 60010:
							m_pipeD.setRotation(180);
							break;
						case 50001:
						case 60001:
							m_pipeD.setRotation(270);
							break;
						}

						if (pipe / 10000 == 6)
						{
							m_pipeD.setTextureRect(sf::IntRect(64, 0, 64, 64));
						}
						else
						{
							m_pipeD.setTextureRect(sf::IntRect(0, 0, 64, 64));
						}

						m_pipeD.setPosition(CELLSIZE * j + CELLSIZE / 2, CELLSIZE * i + CELLSIZE / 2);
						t_window.draw(m_pipeD);

						found = true;
						break;
					}
				}
			}

			if (m_grid[i][j] == 61999)
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
	//checkWater();
}

void Pipe::rotate(sf::Vector2f t_pos)
{
	int posx = t_pos.x / CELLSIZE;
	int posy = t_pos.y / CELLSIZE;

	int pipe = m_grid[posy][posx];

	//check if T pipe
	for (int i = 0; i < 8; i++)
	{
		if (pipe == TPIPE[i])
		{
			//check for water (the last 4 indexes of the array mirror the first 4 but with water, so their value is the same but +10000)
			if (i >= 4)
			{
				i -= 4;		//treat it as if it doesn't have water
			}

			//rotation
			if (i == 3)
			{
				pipe = TPIPE[0];
			}
			else
			{
				pipe = TPIPE[i + 1];
			}

			m_grid[posy][posx] = pipe;
			return;
		}
	}

	//check if L pipe
	for (int i = 0; i < 8; i++)
	{
		if (pipe == LPIPE[i])
		{
			//check for water
			if (i >= 4)
			{
				i -= 4;
			}

			//rotation
			if (i == 3)
			{
				pipe = LPIPE[0];
			}
			else
			{
				pipe = LPIPE[i + 1];
			}

			m_grid[posy][posx] = pipe;
			return;
		}
	}

	//check if I pipe
	for (int i = 0; i < 4; i++)
	{
		if (pipe == IPIPE[i])
		{
			//check for water
			if (i >= 2)
			{
				i -= 2;
			}

			//rotation
			if (i == 1)
			{
				pipe = IPIPE[0];
			}
			else
			{
				pipe = IPIPE[i + 1];
			}

			m_grid[posy][posx] = pipe;
			return;
		}
	}

	//check if D pipe
	for (int i = 0; i < 8; i++)
	{
		if (pipe == DPIPE[i])
		{
			//check for water
			if (i >= 4)
			{
				i -= 4;
			}

			//rotation
			if (i == 3)
			{
				pipe = DPIPE[0];
			}
			else
			{
				pipe = DPIPE[i + 1];
			}

			m_grid[posy][posx] = pipe;
			return;
		}
	}
}

void Pipe::checkWater()
{
	for (int i = 0; i < GRIDSIZE; i++)
	{
		for (int j = 0; i < GRIDSIZE; i++)
		{
			//these are all of the tiles with a pipe connection going up
			if (m_grid[j][i] == 51000 || m_grid[j][i] == 51100 || m_grid[j][i] == 51001 ||m_grid[j][i] == 51010 || 
				m_grid[j][i] == 51101 || m_grid[j][i] == 51110 || m_grid[j][i] == 51011)
			{
				if (m_grid[j - 1][i] == 60110 || m_grid[j - 1][i] == 60011 || m_grid[j - 1][i] == 61010 || m_grid[j - 1][i] == 61110 ||
					m_grid[j - 1][i] == 60111 || m_grid[j - 1][i] == 61011)
				{
					m_grid[j][i] += 10000;
				}
			}
			//these are all of the tiles with a pipe connection going down
			else if (m_grid[i][j] == 50010 || m_grid[i][j] == 50110 || m_grid[i][j] == 50011 || m_grid[i][j] == 51010 || 
					 m_grid[i][j] == 50111 || m_grid[i][j] == 51110 || m_grid[i][j] == 51011)
			{
				if (m_grid[j][i] == 61100 || m_grid[j][i] == 61001 || m_grid[j][i] == 61010 || m_grid[j][i] == 61110 ||
					m_grid[j][i] == 61101 || m_grid[j][i] == 61011 || m_grid[i + 1][j] == 61999)
				{
					std::cout << "asd";
					m_grid[i][j] += 10000;
				}
			}
		}
	}
}

