#include "Enemy.h"

Enemy::Enemy()
{
	initTexture(texturePath);
	initSprite();
}

float Enemy::getMovementSpeed()
{
	return movementSpeed;
}