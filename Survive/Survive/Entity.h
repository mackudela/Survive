#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Entity : public sf::Sprite
{
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float velocityX, float velocityY);
	sf::Vector2f getVelocity() const;

private:
	sf::Vector2f velocity;
};