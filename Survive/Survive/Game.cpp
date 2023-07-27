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
	initFont();
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
	mainWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Survive", sf::Style::Default | sf::Style::Resize);
	mainWindow->setVerticalSyncEnabled(false);
	mainWindow->setView(*mainView);
}

void Game::initView()
{
	mainView = std::make_unique<sf::View>(sf::View(sf::Vector2f(960.f, 540.f), sf::Vector2f(1920.f, 1080.f)));
}

void Game::initBackground()
{
	background = std::make_unique<Background>();
}

void Game::initPlayer()
{
	player = std::make_unique<Player>();
	player->setPosition(mainWindow->getSize().x / 2, mainWindow->getSize().y / 2);
}

void Game::initFont()
{
	if (!font.loadFromFile(g_fontPath))
		std::cout << "Wrong font path";
	playerPositionText.setFont(font);
	playerPositionText.setCharacterSize(24);
	playerPositionText.setFillColor(sf::Color::Red);
	playerPositionText.setStyle(sf::Text::Bold);
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
	updatePlayerMovement(deltaTime);
	//view position
	updateViewPosition();

	//playerPositionText
	playerPositionString = std::to_string(player->getPosition().x) + " " + std::to_string(player->getPosition().y);
	playerPositionText.setPosition(player->getPosition());
	playerPositionText.setString(playerPositionString);
}

void Game::updatePlayerMovement(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	playerMovementSpeed = player->getMovementSpeed();
	playerPosition = player->getPosition();

	if (isMovingUp && playerPosition.y > 2)
		movement.y -= playerMovementSpeed;
	if (isMovingDown && playerPosition.y < (g_backgroundWidth - 2 - player->getTextureSize().y))
		movement.y += playerMovementSpeed;
	if (isMovingLeft && playerPosition.x > 2)
		movement.x -= playerMovementSpeed;
	if (isMovingRight && playerPosition.x < (g_backgroundHeight - 2 - player->getTextureSize().x))
		movement.x += playerMovementSpeed;
	player->move(movement.x * deltaTime.asSeconds(), movement.y * deltaTime.asSeconds());
}

void Game::updateViewPosition()
{
	float viewX;
	float viewY;
	
	if (playerPosition.x > g_viewCenterX - (player->getTextureSize().x / 2))
	{
		if (playerPosition.x < g_backgroundWidth - g_viewCenterX - (player->getTextureSize().x / 2))
		{
			viewX = playerPosition.x;
		}
		else
		{
			viewX = g_backgroundWidth - g_viewCenterX - (player->getTextureSize().x / 2);
		}
	}
	else 
	{
		viewX = g_viewCenterX - (player->getTextureSize().x / 2);
	}

	if (playerPosition.y > g_viewCenterY - (player->getTextureSize().y / 2))
	{
		if (playerPosition.y < g_backgroundHeight - g_viewCenterY - (player->getTextureSize().y / 2))
		{
			viewY = playerPosition.y;
		}
		else
		{
			viewY = g_backgroundHeight - g_viewCenterY - (player->getTextureSize().y / 2);
		}
	}
	else 
	{
		viewY = g_viewCenterY - (player->getTextureSize().y / 2);
	}

	mainView->setCenter(
		{ viewX + (player->getTextureSize().x / 2),
		viewY + (player->getTextureSize().y / 2) });

	mainWindow->setView(*mainView);
}

//Renders game to the screen
void Game::render()
{
	mainWindow->clear();

	//draw everything
	background->render(*mainWindow);
	player->render(*mainWindow);
	//playerPositionText
	mainWindow->draw(playerPositionText);

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
