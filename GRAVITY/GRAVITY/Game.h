// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	
private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void setUpShapes();

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

	sf::CircleShape shape;
	sf::Vector2f position = {400.f,600.f};
	sf::RectangleShape base;
	sf::Vector2f basePos={ 0.f, 600.f };
	float timeTaken = {0.0f};
	float myTimeTaken = { 0.0f };
	float maxHeight = { 0.0f };
	float myMaxHeight = { 0.0f };
	bool inSky = {true};

	sf::Vector2f velocity={ 0.f, 0.f };
	sf::Vector2f gravity={ 0.f, 9.8f };

};

#endif // !GAME