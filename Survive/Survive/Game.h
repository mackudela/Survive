#pragma once
#include <iostream>

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
	void update(sf::Time);
	void render();

	void handlePlayerInput(sf::Keyboard::Key, bool);
private:
	sf::RenderWindow mainWindow;
	sf::Texture playerTexture;
	sf::Sprite player;
	bool isMovingUp;
	bool isMovingDown;
	bool isMovingLeft;
	bool isMovingRight;
	const float playerSpeed = 100.f;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
};