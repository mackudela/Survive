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
	initEnemy();
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
	player->setPosition(mainWindow->getSize().x / 2.f, mainWindow->getSize().y / 2.f);
}

void Game::initEnemy()
{
	enemy = std::make_unique<Enemy>();
	enemy->setPosition(300, 300);
}

void Game::initFont()
{
	if (!font.loadFromFile(fontPath))
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
			case sf::Event::MouseButtonPressed:
				playerAttackSpell(sf::Mouse::getPosition());
				std::cout << "mouse left\n";
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
	//check collisions	
	if(player->checkCollision(enemy->getGlobalBounds()))
		//std::cout << "COLLIDING";

	//player movement
	updatePlayerMovement(deltaTime);

	//enemy movement
	updateEnemyMovement(deltaTime);

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
	if (isMovingRight && (isMovingDown || isMovingUp))
	{
		movement *= 0.7f;
	}
	else if (isMovingLeft && (isMovingDown || isMovingUp))
	{
		movement *= 0.7f;
	}
	player->move(movement.x * deltaTime.asSeconds(), movement.y * deltaTime.asSeconds());
}

void Game::updateEnemyMovement(sf::Time deltaTime)
{
	sf::Vector2f direction = player->getCenterPosition() - enemy->getCenterPosition();
	direction = normalizeVector(direction);
	enemy->move(direction * deltaTime.asSeconds() * enemy->getMovementSpeed());
}

sf::Vector2f Game::normalizeVector(sf::Vector2f vector)
{
	float magnitude = sqrtf(vector.x * vector.x + vector.y * vector.y);
	if (magnitude != 0)
	{
		vector.x /= magnitude;
		vector.y /= magnitude;
	}
	return vector;
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
	enemy->render(*mainWindow);
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
	else if (key == sf::Mouse::Left)
	{
		/*playerAttackSpell(sf::Mouse::getPosition());
		std::cout << "mouse left\n";*/
	}
}

void Game::playerAttackSpell(sf::Vector2i mouseCords)
{
	sf::Vector2f mouseWorldCords = mainWindow->mapPixelToCoords(mouseCords);
	sf::Vector2f direction = mouseWorldCords - player->getCenterPosition();
	direction = normalizeVector(direction);
	player->attackSpell(direction);
}
