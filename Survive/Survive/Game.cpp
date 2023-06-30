#include "Game.h"

Game::Game() : 
	player(), 
	isMovingUp(false),
	isMovingDown(false),
	isMovingLeft(false),
	isMovingRight(false)
{
	initWindow();
	player.setPosition(100.f, 100.f);
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mainWindow->isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);

		}
		render();
	}
}

void Game::initWindow()
{
	mainWindow = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Survive", sf::Style::Default | sf::Style::Close);
	mainWindow->setVerticalSyncEnabled(true);

}

//Handles user input
void Game::processEvents()
{
	sf::Event event;
	while (mainWindow->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mainWindow->close();
				break;
			default:
				break;
		}
	}
}

//Updates the game logic
void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (isMovingUp)
		movement.y -= player.getPlayerSpeed();
	if (isMovingDown)
		movement.y += player.getPlayerSpeed();
	if (isMovingLeft)
		movement.x -= player.getPlayerSpeed();
	if (isMovingRight)
		movement.x += player.getPlayerSpeed();

	player.move(movement * deltaTime.asSeconds());
}

//Renders game to the screen
void Game::render()
{
	mainWindow->clear();
	mainWindow->draw(player);
	mainWindow->display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		isMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		isMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		isMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		isMovingRight = isPressed;
}
