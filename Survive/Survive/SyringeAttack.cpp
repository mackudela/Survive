#include "SyringeAttack.h"

SyringeAttack::SyringeAttack(float posX, float posY, sf::Vector2f direction) : 
	direction(direction)
{
	initTexture(texturePath);
	initSprite();

	sprite.setOrigin((sf::Vector2f)texture.getSize() / 2.f);
	setPosition(posX, posY);
	rotate(direction);
	lifespan.restart();
}

sf::Sprite SyringeAttack::getSprite()
{
	return sprite;
}

sf::Vector2f SyringeAttack::getDirection()
{
	return direction;
}

bool SyringeAttack::isAlive()
{
	if (lifespan.getElapsedTime().asSeconds() < 3)
		return true;
	return false;
}
