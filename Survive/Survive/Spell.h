#pragma once

#include "Entity.h"

class Spell : public Entity
{
public:
	sf::Sprite getSprite();
	float getDamage();

protected:
	float damage;
};