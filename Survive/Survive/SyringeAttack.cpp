#include "SyringeAttack.h"

SyringeAttack::SyringeAttack(float posX, float posY)
{
	initTexture(texturePath);
	initSprite();

	setPosition(posX, posY);
}

sf::Sprite SyringeAttack::getSprite()
{
	return sprite;
}
