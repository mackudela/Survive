#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Animation
{
public:
	Animation(std::string texturePath, int numFrames, float frameDuration);

	void update(sf::Time dt);
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void move(float x, float y, sf::Time dt);
	void move(sf::Vector2f direction, sf::Time dt);
	void draw(sf::RenderTarget& window);
	bool checkCollisions(sf::FloatRect entity);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getCenterPosition();
	sf::Vector2u getTextureSize();
	sf::Sprite getSprite();

private:
	void initTexture(std::string texturePath);

	sf::Texture texture;
	sf::Sprite sprite;
	std::vector<sf::IntRect> frames;
	int currentFrame;
	float frameDuration;
	float elapsedFrameTime;
};