#pragma once

#include "Entity.h"

class Spell : public Entity
{
public:
	float getDamage();

protected:
	float damage;
};