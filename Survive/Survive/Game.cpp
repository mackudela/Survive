#include "Game.h"

Game::Game() : 
	isMovingUp(false),
	isMovingDown(false),
	isMovingLeft(false),
	isMovingRight(false)
{
	initView();
	initWindow();
	initBackground();
	initPlayer();
}

Game::~Game()
{
	delete mainWindow;
	delete mainView;
	delete player;
	delete background;
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
	mainWindow = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Survive", sf::Style::Default | sf::Style::Resize);
	mainWindow->setVerticalSyncEnabled(false);
	mainWindow->setView(*mainView);
}

void Game::initView()
{
	mainView = new sf::View(sf::Vector2f(960.f, 540.f), sf::Vector2f(1920.f, 1080.f));
}

void Game::initBackground()
{
	background = new Background();
}

void Game::initPlayer()
{
	player = new Player();
	player->setPosition(mainWindow->getSize().x / 2 - 50, mainWindow->getSize().y / 2 - 50);
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
		movement.y -= player->getMovementSpeed();
	if (isMovingDown)
		movement.y += player->getMovementSpeed();
	if (isMovingLeft)
		movement.x -= player->getMovementSpeed();
	if (isMovingRight)
		movement.x += player->getMovementSpeed();

	player->move(movement.x * deltaTime.asSeconds(), movement.y * deltaTime.asSeconds());
	mainView->setCenter(player->getPosition());
	mainWindow->setView(*mainView);
}

//Renders game to the screen
void Game::render()
{
	mainWindow->clear();

	//draw everything
	background->render(*mainWindow);
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
