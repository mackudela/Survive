#pragma once

#include "Entity.h"

class Spell : public Entity
{
public:
	float getDamage();
	virtual sf::Vector2f getDirection();
	virtual bool isAlive();
	virtual float getSpeed();

protected:
	float damage;
	sf::Vector2f direction;
	float speed;
};