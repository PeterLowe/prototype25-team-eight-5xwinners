#include "Hud.h"

Hud::Hud()
{
	setupText();
	setupContent();
}

void Hud::setupContent()
{
	m_testBackBoard.setSize(sf::Vector2f{ 750, 200 });
	m_testBackBoard.setOutlineColor(sf::Color::Blue);
	m_testBackBoard.setOutlineThickness(-10.0f);
	m_testBackBoard.setPosition(0.0, 550);
	m_testBackBoard.setFillColor(sf::Color::Black);

	//m_item1.setOrigin(?,?);
	m_item1.setPosition(120.0f, 585.0f);

	//m_item2.setOrigin(?,?);
	m_item2.setPosition(320.0f, 585.0f);

	//m_item3.setOrigin(?,?);
	m_item3.setPosition(520.0f, 585.0f);

	//m_item4.setOrigin(?,?);
	m_item4.setPosition(120.0f, 640.0f);

	//m_item5.setOrigin(?,?);
	m_item5.setPosition(320.0f, 640.0f);

	//m_item6.setOrigin(?,?);
	m_item6.setPosition(520.0f, 640.0f);

	//m_item7.setOrigin(?,?);
	m_item7.setPosition(120.0f, 695.0f);

	//m_item8.setOrigin(?,?);
	m_item8.setPosition(320.0f, 695.0f);

	//m_item9.setOrigin(?,?);
	m_item9.setPosition(520.0f, 695.0f);
}

void Hud::setupText()
{
	if (!m_font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "Issue loading hud font" << std::endl;
	}

	m_item1.setFont(m_font);
	m_item1.setCharacterSize(16);
	m_item1.setFillColor(sf::Color::White);
	m_item1.setString("Watch");

	m_item2.setFont(m_font);
	m_item2.setCharacterSize(16);
	m_item2.setFillColor(sf::Color::White);
	m_item2.setString("Necklace");

	m_item3.setFont(m_font);
	m_item3.setCharacterSize(16);
	m_item3.setFillColor(sf::Color::White);
	m_item3.setString("Purse");

	m_item4.setFont(m_font);
	m_item4.setCharacterSize(16);
	m_item4.setFillColor(sf::Color::White);
	m_item4.setString("Medicine");

	m_item5.setFont(m_font);
	m_item5.setCharacterSize(16);
	m_item5.setFillColor(sf::Color::White);
	m_item5.setString("placeholder5");

	m_item6.setFont(m_font);
	m_item6.setCharacterSize(16);
	m_item6.setFillColor(sf::Color::White);
	m_item6.setString("placeholder6");

	m_item7.setFont(m_font);
	m_item7.setCharacterSize(16);
	m_item7.setFillColor(sf::Color::White);
	m_item7.setString("Coat");

	m_item8.setFont(m_font);
	m_item8.setCharacterSize(16);
	m_item8.setFillColor(sf::Color::White);
	m_item8.setString("placeholder8");

	m_item9.setFont(m_font);
	m_item9.setCharacterSize(16);
	m_item9.setFillColor(sf::Color::White);
	m_item9.setString("Saber");
}

void Hud::itemObtained(int t_itemNum)
{
	switch (t_itemNum)
	{
	case 1:
		m_item1.setFillColor(sf::Color(150, 150, 150));
		break;
	case 2:
		m_item2.setFillColor(sf::Color(150, 150, 150));
		break;
	case 3:
		m_item3.setFillColor(sf::Color(150, 150, 150));
		break;
	case 4:
		m_item4.setFillColor(sf::Color(150, 150, 150));
		break;
	case 5:
		m_item5.setFillColor(sf::Color(150, 150, 150));
		break;
	case 6:
		m_item6.setFillColor(sf::Color(150, 150, 150));
		break;
	case 7:
		m_item7.setFillColor(sf::Color(150, 150, 150));
		break;
	case 8:
		m_item8.setFillColor(sf::Color(150, 150, 150));
		break;
	case 9:
		m_item9.setFillColor(sf::Color(150, 150, 150));
		break;
	}
}

void Hud::on()
{
	m_hudDisplay = true;
}

void Hud::off()
{
	m_hudDisplay = false;
}

bool Hud::display()
{
	return m_hudDisplay;
}

sf::RectangleShape Hud::getBackground()
{
	return m_testBackBoard;
}

sf::Text Hud::getItem1()
{
	return m_item1;
}

sf::Text Hud::getItem2()
{
	return m_item2;
}

sf::Text Hud::getItem3()
{
	return m_item3;
}

sf::Text Hud::getItem4()
{
	return m_item4;
}

sf::Text Hud::getItem5()
{
	return m_item5;
}

sf::Text Hud::getItem6()
{
	return m_item6;
}

sf::Text Hud::getItem7()
{
	return m_item7;
}

sf::Text Hud::getItem8()
{
	return m_item8;
}

sf::Text Hud::getItem9()
{
	return m_item9;
}