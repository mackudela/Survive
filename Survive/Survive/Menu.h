#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

class Menu {
public:
	Menu();
	void loopEvents();
	void draw();
	void runMenu();

private:
	int position;
	bool isPressed, isSelected;
	const std::string fontPath = "media\\fonts\\BUNGEE_SPICE_REGULAR.ttf";
	const std::string menuBackgroundPath = "media\\Textures\\menuBackground.jpg";

	std::unique_ptr<sf::RenderWindow> menuWindow;
	std::unique_ptr<sf::RectangleShape> winClose;
	std::unique_ptr<sf::Font> font;
	std::unique_ptr<sf::Texture> image;
	std::unique_ptr<sf::Sprite> background;

	sf::Vector2i mousePosition;
	sf::Vector2f mouseCords;

	std::vector<std::string> options;
	std::vector<sf::Vector2f> cords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> textSizes;

	void setValues();
	
};