#pragma once

#include <cmath>

#include "Entity.h"

class SyringeAttack : public Entity
{
public:
	SyringeAttack(float posX, float posY, sf::Vector2f direction);
	sf::Sprite getSprite();
	sf::Vector2f getDirection();

private:
	const std::string texturePath = "media\\textures\\syringe.png";
	sf::Vector2f direction;

};