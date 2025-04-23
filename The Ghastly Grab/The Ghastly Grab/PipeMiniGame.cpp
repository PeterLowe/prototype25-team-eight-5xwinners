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
	m_player.setPosition(sf::Vector2f(0.0f, 0.0f ));
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
							m_pipeI.setRotation(90);
							break;
						case 50101:
						case 60101:
							m_pipeI.setRotation(0);
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
			break;
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
			break;
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
			break;
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
			break;
		}
	}

	checkWater();
}

void Pipe::checkWater()
{
	int waterFlow[10][10];				//new 2d array to store information about water and forks

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			waterFlow[i][j] = 50;		//the first digit handles water, 5 means no water, 6 means has water. The second digit represents a fork, 0 is no fork, 1 means there is a fork
		}
	}

	waterFlow[8][4] = 60;				//the source tile starts with water

	int posx = 4;						//our starting position is the source tile
	int posy = 8;
		
	int numPath = 1;					//this tracks the number of paths in the maze that haven't resulted in a dead end yet

	while (numPath > 0)					//we keep looping until all paths result in a dead end
	{
   		bool upPipe = false;			//these bools track if our current position has a pipe going in a particular direction
		bool rightPipe = false;
		bool downPipe = false;
		bool leftPipe = false;

		bool moved = false;


		checkDirection(posx, posy, upPipe, rightPipe, downPipe, leftPipe);
		std::cout << "PosX: " << posx << " PosY: " << posy << " UpPipe: " << upPipe << " RightPipe: " << rightPipe << " DownPipe: " << downPipe << " LeftPipe: " << leftPipe << std::endl;


		//in this next section we're going to check the relevant neighboring tiles to see if they have a pipe that makes a viable connection with our tile

		int connections = 0;			//this tracks how many successful connections we have between the pipe on our current tile and the neighboring tiles. Used for determining if we have forks
		bool hasConnection = false;		//used to track if we have at least one viable connection

		if (upPipe)			//if our pipe has a side going up 
		{
			for (int i = 0; i < 14; i++)
			{
				if (m_grid[posy - 1][posx] == DOWN_CON[i] && waterFlow[posy - 1][posx] / 10 == 5)	//if the pipe above = one of the 14 possible pipe/rotation combos that has a downward facing pipe and has no water
				{
					connections++;			//it connects
					hasConnection = true;	//make a note of it
					break;
				}
			}
		}
		if (rightPipe)
		{
			for (int i = 0; i < 14; i++)
			{
				if (m_grid[posy][posx + 1] == LEFT_CON[i] && waterFlow[posy][posx + 1] / 10 == 5)
				{
					connections++;
					hasConnection = true;
					break;
				}
			}
		}
		if (downPipe)
		{
			for (int i = 0; i < 14; i++)
			{
				if (m_grid[posy + 1][posx] == UP_CON[i] && waterFlow[posy + 1][posx] / 10 == 5)
				{
					connections++;
					hasConnection = true;
					break;
				}
			}
		}
		if (leftPipe)
		{
			for (int i = 0; i < 14; i++)
			{
				if (m_grid[posy][posx - 1] == RIGHT_CON[i] && waterFlow[posy][posx - 1] / 10 == 5)
				{
					connections++;
					hasConnection = true;
					break;
				}
			}
		}

		std::cout << "connections: " << connections << std::endl;
		if (!hasConnection)		//if there was no viable connections
		{
			numPath--;			//it was a dead end so the number of possible paths is reduced
		}


		//now that the connections are calculated, we update our array with water and forks where appropriate

		if (waterFlow[posy][posx] % 10 == 0 && connections >= 2)	//if the value of this tile is 50 or 60 (should always be 60 at this point) and more than 1 connection
		{
			waterFlow[posy][posx] += 1;		//we update the array to have a fork 
			std::cout << "more than 2 connection so +1" << std::endl;
		}
		else
		{
			std::cout << "less than 2 connection" << std::endl;
		}


		//next we're going to move to a new tile
	

		if (upPipe)			//if our pipe has a side going up
		{
			for (int i = 0; i < 14; i++)
			{
				if (m_grid[posy - 1][posx] == DOWN_CON[i] && waterFlow[posy - 1][posx] / 10 == 5)	//if the pipe above = one of the 14 possible pipe/rotation combos that has a downward facing pipe and has no water
				{
					posy -= 1;						//we move there
					waterFlow[posy][posx] += 10;	//and it gets water
					moved = true;
					break;
				}
			}
		}
		if (rightPipe && !moved)
		{
			for (int i = 0; i < 14; i++)
			{
				if (m_grid[posy][posx + 1] == LEFT_CON[i] && waterFlow[posy][posx + 1] / 10 == 5)
				{
					posx += 1;
					waterFlow[posy][posx] += 10;
					moved = true;
					break;
				}
			}
		}
		if (downPipe && !moved)
		{
			for (int i = 0; i < 14; i++)
			{
				if (m_grid[posy + 1][posx] == UP_CON[i] && waterFlow[posy + 1][posx] / 10 == 5)
				{
					posy += 1;
					waterFlow[posy][posx] += 10;
					moved = true;
					break;
				}
			}
		}
		if (leftPipe && !moved)
		{
			for (int i = 0; i < 14; i++)
			{
				if (m_grid[posy][posx - 1] == RIGHT_CON[i] && waterFlow[posy][posx - 1] / 10 == 5)
				{
					posx -= 1;
					waterFlow[posy][posx] += 10;
					break;
				}
			}
		}


		//if we got this far but ran into a dead end so numPath is now 0, we check for the existence of a fork in the array, move there, and set numPath back to 1

		if (numPath == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (waterFlow[i][j] == 61)		//if a fork tile exists. It should already have water since we've been there before
					{
						posx = j;					//set our position to that tile
						posy = i;
						numPath++;					//add 1 to path so we can enter the loop again
						waterFlow[i][j]--;
					}
				}
			}
		}

		std::cout << "-------------------------" << std::endl;
	}


	//update the m_grid array based on the final results of the waterFlow array

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (waterFlow[i][j] / 10 == 6)
			{
				if (m_grid[i][j] / 10000 == 5)
				{
					m_grid[i][j] += 10000;
				}
			}
			else
			{
				if (m_grid[i][j] / 10000 == 6)
				{
					m_grid[i][j] -= 10000;
				}
			}
		}
	}
}

void Pipe::checkDirection(int t_posx, int t_posy, bool& t_up, bool& t_right, bool& t_down, bool& t_left)
{
	int pipe = m_grid[t_posy][t_posx];

	for (int i = 0; i < 14; i++)
	{
		if (pipe == UP_CON[i])
		{
			t_up = true;
		}
		if (pipe == RIGHT_CON[i])
		{
			t_right = true;
		}
		if (pipe == DOWN_CON[i])
		{
			t_down = true;
		}
		if (pipe == LEFT_CON[i])
		{
			t_left = true;
		}
	}
	if (pipe == 61999)
	{
		t_up = true;
	}
}

