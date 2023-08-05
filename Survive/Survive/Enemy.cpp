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

sf::Vector2u Enemy::getTextureSize()
{
	return texture.getSize();
}

sf::Vector2f Enemy::getEnemyCenterPosition()
{
	sf::Vector2f position;
	position.x = sprite.getPosition().x + (getTextureSize().x / 2);
	position.y = sprite.getPosition().y + (getTextureSize().y / 2);
	return position;
}
