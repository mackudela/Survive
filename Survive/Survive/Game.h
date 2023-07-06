#pragma once
#include <iostream>

#include "Player.h"

class Game
{ 
public:
	Game();
	~Game();
	void run();
private:
	void initWindow();
	void initPlayer();
	void processEvents();
	void update(sf::Time time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	

	sf::RenderWindow* mainWindow;
	Player* player;
	bool isMovingUp;
	bool isMovingDown;
	bool isMovingLeft;
	bool isMovingRight;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
};