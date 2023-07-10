#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Background {
public:

	Background();
	void update();
	void render(sf::RenderTarget& target);
	void move(const float x, const float y);
	void setPosition(const float x, const float y);

private:

	void initTexture();
	void initSprite();

	sf::Sprite sprite;
	sf::Texture texture;
};