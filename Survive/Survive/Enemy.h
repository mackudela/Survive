#pragma once
#include "Entity.h"

const std::string g_enemyTexturePath = "media\\textures\\enemy.png";
const float g_enemyMovementSpeed = 400.f;

class Enemy : public Entity
{
public:
	Enemy();
	float getMovementSpeed();
protected:

	
private:
	float movementSpeed = g_enemyMovementSpeed;
};