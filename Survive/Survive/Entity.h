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
	virtual void render(sf::RenderTarget& target);
	virtual void move(const float x, const float y);
	virtual void move(sf::Vector2f direction);
	void setPosition(const float x, const float y);
	void rotate(sf::Vector2f direction);
	bool checkCollision(sf::FloatRect entity);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getCenterPosition();
	sf::Vector2u getTextureSize();
	sf::Sprite getSprite();

protected:
	sf::Sprite sprite;
	sf::Texture texture;

	virtual void initTexture(std::string texturePath);
	virtual void initSprite();
};