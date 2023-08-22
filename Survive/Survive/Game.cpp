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
	initEnemySpawner();
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

void Game::initEnemySpawner()
{
	enemySpawner = std::make_unique<EnemySpawner>();
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
				playerAttackSpell(sf::Mouse::getPosition(*mainWindow));
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
	checkCollisions();

	//player movement
	updatePlayerMovement(deltaTime);

	//enemy movement
	updateEnemyMovement(deltaTime);
	enemySpawner->spawnEnemies();

	//view position
	updateViewPosition();
}

void Game::updatePlayerMovement(sf::Time deltaTime)
{
	sf::Vector2f movement = calculatePlayerMovement();
	player->move(movement.x * deltaTime.asSeconds(), movement.y * deltaTime.asSeconds(), deltaTime);
}

sf::Vector2f Game::calculatePlayerMovement()
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
	return movement;
}

void Game::updateEnemyMovement(sf::Time deltaTime)
{
	enemySpawner->moveEnemies(deltaTime, player->getCenterPosition());
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
	sf::Vector2f viewPosition = calculateViewPosition();
	mainView->setCenter(
		{ viewPosition.x + (player->getTextureSize().x / 2),
		viewPosition.y + (player->getTextureSize().y / 2) });

	mainWindow->setView(*mainView);
}

sf::Vector2f Game::calculateViewPosition()
{
	sf::Vector2f viewPosition;

	if (playerPosition.x > g_viewCenterX - (player->getTextureSize().x / 2))
	{
		if (playerPosition.x < g_backgroundWidth - g_viewCenterX - (player->getTextureSize().x / 2))
		{
			viewPosition.x = playerPosition.x;
		}
		else
		{
			viewPosition.x = g_backgroundWidth - g_viewCenterX - (player->getTextureSize().x / 2);
		}
	}
	else
	{
		viewPosition.x = g_viewCenterX - (player->getTextureSize().x / 2);
	}

	if (playerPosition.y > g_viewCenterY - (player->getTextureSize().y / 2))
	{
		if (playerPosition.y < g_backgroundHeight - g_viewCenterY - (player->getTextureSize().y / 2))
		{
			viewPosition.y = playerPosition.y;
		}
		else
		{
			viewPosition.y = g_backgroundHeight - g_viewCenterY - (player->getTextureSize().y / 2);
		}
	}
	else
	{
		viewPosition.y = g_viewCenterY - (player->getTextureSize().y / 2);
	}
	return viewPosition;
}

//Renders game to the screen
void Game::render()
{
	//clear window
	mainWindow->clear();

	//draw everything
	background->render(*mainWindow);
	player->render(*mainWindow);
	enemySpawner->render(*mainWindow);

	//display
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

void Game::playerAttackSpell(sf::Vector2i mouseCords)
{
	sf::Vector2f mouseWorldCords = mainWindow->mapPixelToCoords(mouseCords);
	sf::Vector2f direction = mouseWorldCords - player->getCenterPosition();
	direction = normalizeVector(direction);
	player->attackSpell(direction);
}

void Game::checkCollisions()
{
	auto playerSpells = player->getPlayerSpells();
	auto enemies = enemySpawner->getEnemies();
	bool destroyedSpell = false;

	for (auto& spell : playerSpells)
	{
		destroyedSpell = false;
		if (spell.first.use_count() != 1)
		{
			for (auto& enemy : enemies)
			{
				if (enemy.first.use_count() != 1 && !destroyedSpell)
				{
					if (spell.first->checkCollision(enemy.first->getGlobalBounds()))
					{
						enemy.first->receiveDamage(spell.first->getDamage());

						player->destroySpell(spell.first);
						destroyedSpell = true;

						if (enemy.first->getHP() <= 0)
						{
							enemySpawner->destroyEnemy(enemy.first);
						}
					}
				}
			}
		}
	}
	//bool destroySpell = false;
	//for (auto itSpells = playerSpells.begin(); itSpells != playerSpells.end();)
	//{
	//	if (itSpells->first.use_count() != 1)
	//	{
	//		for (auto itEnemies = enemies.begin(); itEnemies != enemies.end();)
	//		{
	//			if (itSpells->first.use_count() != 1 && itEnemies->first.use_count() != 1)
	//			{
	//				if (itSpells->first->checkCollision(itEnemies->first->getGlobalBounds()))
	//				{
	//					itEnemies->first->receiveDamage(itSpells->first->getDamage());
	//					player->destroySpell(itSpells->first);
	//					if (itEnemies->first->getHP() <= 0)
	//					{
	//						enemySpawner->destroyEnemy(itEnemies->first);
	//						//enemies.erase(itEnemies++);
	//					}
	//					else
	//					{
	//						++itEnemies;
	//					}
	//					//playerSpells.erase(itSpells++);
	//				}
	//				else
	//				{
	//					++itEnemies;
	//					//++itSpells;
	//				}
	//			}
	//		}
	//	}
	//	++itSpells;
	//}
}
