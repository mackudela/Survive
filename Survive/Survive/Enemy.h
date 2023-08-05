#pragma once
#include "Entity.h"

const std::string g_enemyTexturePath = "media\\textures\\enemy.png";
const float g_enemyMovementSpeed = 400.f;

class Enemy : public Entity
{
public:
	Enemy();
	float getMovementSpeed();
	sf::Vector2u getTextureSize();
	sf::Vector2f getEnemyCenterPosition();
protected:

private:
	float movementSpeed = g_enemyMovementSpeed;
};