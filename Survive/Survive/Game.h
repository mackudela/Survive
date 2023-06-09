#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();

	void handlePlayerInput(sf::Keyboard::Key, bool);
private:
	sf::RenderWindow mainWindow;
	sf::CircleShape player;
	bool isMovingUp;
	bool isMovingDown;
	bool isMovingLeft;
	bool isMovingRight;
};