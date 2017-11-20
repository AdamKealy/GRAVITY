/// <summary>
/// @author Adam Kealy
/// @date Nov
/// </summary>
#include <SFML\Graphics.hpp>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 




/// <summary>
/// main enrtry point
/// </summary>
/// <returns>zero</returns>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Go Physics!!");

	sf::CircleShape shape(0.5f);
	sf::RectangleShape base(sf::Vector2f(800.f, 200.f));

	shape.setFillColor(sf::Color::Green);
	base.setFillColor(sf::Color::Blue);

	sf::Vector2f velocity(0, 0);

	sf::Vector2f position(400, 400);
	sf::Vector2f basePos(0.f, 600.f);

	sf::Vector2f gravity(0.0f, 9.8f);

	sf::Clock clock;

	const float FPS = 60.0f;

	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	clock.restart();

	while (window.isOpen())

	{

		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::TextEntered:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					position.y -= 5;
					break;
				}
			}
			//get the time since last update and restart the clock

			timeSinceLastUpdate += clock.restart();

			//update every 60th of a second



			if (timeSinceLastUpdate > timePerFrame)

			{

				window.clear();

				// update position and velocity here using equations in lab sheet using timeChange as timeSinceLastUpdate.asSeconds().
				position.y += gravity.y;
				//update shape on screen

				shape.setPosition(position);
				base.setPosition(basePos);


				window.draw(shape);
				window.draw(base);

				window.display();

				timeSinceLastUpdate = sf::Time::Zero;

			}

		}
	}
	return 0;
}