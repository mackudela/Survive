#include "SyringeAttack.h"

SyringeAttack::SyringeAttack(float posX, float posY, sf::Vector2f direction) : 
	direction(direction)
{
	initTexture(texturePath);
	initSprite();

	setPosition(posX, posY);
}

sf::Sprite SyringeAttack::getSprite()
{
	return sprite;
}

sf::Vector2f SyringeAttack::getDirection()
{
	return direction;
}
