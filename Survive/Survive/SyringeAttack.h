#pragma once

#include <cmath>

#include "Spell.h"

class SyringeAttack : public Spell
{
public:
	SyringeAttack(float posX, float posY, sf::Vector2f direction, float speed, float damage);
	sf::Vector2f getDirection();
	float getSpeed();
	bool isAlive();

private:
	const std::string texturePath = "media\\textures\\syringe.png";
	sf::Vector2f direction;
	sf::Clock lifespan;
	float speed;
};