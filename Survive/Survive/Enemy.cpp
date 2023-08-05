#include "Enemy.h"

Enemy::Enemy()
{
	initTexture(g_enemyTexturePath);
	initSprite();
}

float Enemy::getMovementSpeed()
{
	return movementSpeed;
}
