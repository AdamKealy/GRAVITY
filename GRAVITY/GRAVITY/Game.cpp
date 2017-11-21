
#include "Game.h"
#include <iostream>


Game::Game() :
	m_window{ sf::VideoMode{ 800, 800, 32 }, "Go Phsics yay! =3" },
	m_exitGame{false} //when true game will exit
{
	
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	setUpShapes();
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::setUpShapes()
{

	shape.setFillColor(sf::Color::Green);
	shape.setPosition(position);
	shape.setRadius(0.5f);

	base.setFillColor(sf::Color::Blue);
	base.setSize(sf::Vector2f(800, 200));
	base.setPosition(basePos);
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (!shape.getGlobalBounds().intersects(base.getGlobalBounds()))
	{
		position.y += gravity.y;
	}

	shape.setPosition(position);

	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear();
	m_window.draw(base);
	m_window.draw(shape);
	m_window.display();
}
