#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"

class Game
{ 
public:
	Game();
	~Game();
	void run();
private:
	void initWindow();
	void processEvents();
	void update(sf::Time time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	sf::RenderWindow* mainWindow;
	Player player;
	bool isMovingUp;
	bool isMovingDown;
	bool isMovingLeft;
	bool isMovingRight;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
};