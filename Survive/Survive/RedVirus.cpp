#include "RedVirus.h"

RedVirus::RedVirus(float posX, float posY)
{
	XP = 10.f;
	currentHP = maxHP = 100.f;
	movementSpeed = 400.f;

	initTexture(texturePath);
	initSprite();
	//sprite.setOrigin((sf::Vector2f)texture.getSize() / 2.f);
	sprite.setPosition(posX, posY);
	initHPBar();
}
