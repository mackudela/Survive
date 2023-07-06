#include "Game.h"

Game::Game() : 
	isMovingUp(false),
	isMovingDown(false),
	isMovingLeft(false),
	isMovingRight(false)
{
	initWindow();
	initPlayer();
}

Game::~Game()
{
	delete mainWindow;
	delete player;
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
	mainWindow->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
	player = new Player();
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
	//player movement
	sf::Vector2f movement(0.f, 0.f);
	if (isMovingUp)
		movement.y -= player->getPlayerSpeed();
	if (isMovingDown)
		movement.y += player->getPlayerSpeed();
	if (isMovingLeft)
		movement.x -= player->getPlayerSpeed();
	if (isMovingRight)
		movement.x += player->getPlayerSpeed();

	player->move(movement.x * deltaTime.asSeconds(), movement.y * deltaTime.asSeconds());
}

//Renders game to the screen
void Game::render()
{
	mainWindow->clear();

	//draw everything
	player->render(*mainWindow);

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
