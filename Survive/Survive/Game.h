#pragma once
#include <iostream>
#include <memory>

#include "Player.h"
#include "Background.h"

class Game
{ 
public:

	Game();
	~Game();
	void run();

private:

	void initWindow();
	void initView();
	void initBackground();
	void initPlayer();
	void processEvents();
	void update(sf::Time time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	sf::RenderWindow* mainWindow;
	sf::View* mainView;
	Player* player;
	Background* background;
	

	bool isMovingUp;
	bool isMovingDown;
	bool isMovingLeft;
	bool isMovingRight;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
};