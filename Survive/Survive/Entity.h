#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Entity
{
public:
	const sf::Vector2f getPosition();

	void update();
	void render(sf::RenderTarget& target);
	void move(const float x, const float y);
	void move(sf::Vector2f direction);
	void setPosition(const float x, const float y);
	virtual bool checkCollision(sf::FloatRect entity);
	sf::FloatRect getGlobalBounds();

protected:
	sf::Sprite sprite;
	sf::Texture texture;

	virtual void initTexture(std::string texturePath);
	virtual void initSprite();
};