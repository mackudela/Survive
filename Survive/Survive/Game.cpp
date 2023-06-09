#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Game.h"

Game::Game() : mainWindow(sf::VideoMode(800, 600), "Survive"), player()
{
	isMovingUp = false;
	isMovingDown = false;
	isMovingLeft = false;
	isMovingRight = false;
	player.setRadius(40.f);
	player.setPosition(100.f, 100.f);
	player.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
	while (mainWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

//Handles user input
void Game::processEvents()
{
	sf::Event event;
	while (mainWindow.pollEvent(event))
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
				mainWindow.close();
				break;
			default:
				break;
		}
	}
}

//Updates the game logic
void Game::update()
{
	sf::Vector2f movement(0.f, 0.f);
	if (isMovingUp)
		movement.y -= 1.f;
	if (isMovingDown)
		movement.y += 1.f;
	if (isMovingLeft)
		movement.x -= 1.f;
	if (isMovingRight)
		movement.x += 1.f;

	player.move(movement);
}

//Renders game to the screen
void Game::render()
{
	mainWindow.clear();
	mainWindow.draw(player);
	mainWindow.display();
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
