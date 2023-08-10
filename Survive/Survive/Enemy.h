#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	float getMovementSpeed();
protected:

private:
	float movementSpeed = 400.f;
	const std::string texturePath = "media\\textures\\enemy.png";
};