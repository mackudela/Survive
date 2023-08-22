#include "SyringeAttack.h"

SyringeAttack::SyringeAttack(float posX, float posY, sf::Vector2f direction, float speed, float damage) : 
	direction(direction), speed(speed)
{
	this->damage = damage;
	initTexture(texturePath);
	initSprite();

	sprite.setOrigin((sf::Vector2f)texture.getSize() / 2.f);
	setPosition(posX, posY);
	rotate(direction);
	lifespan.restart();
}

sf::Vector2f SyringeAttack::getDirection()
{
	return direction;
}

float SyringeAttack::getSpeed()
{
	return speed;
}

bool SyringeAttack::isAlive()
{
	if (lifespan.getElapsedTime().asSeconds() < 3)
		return true;
	return false;
}