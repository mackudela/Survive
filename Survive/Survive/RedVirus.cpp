#include "RedVirus.h"

RedVirus::RedVirus(float posX, float posY)
{
	XP = 10.f;
	currentHP = maxHP = 100.f;
	movementSpeed = 250.f;

	initTexture(texturePath);
	initSprite();
	sprite.setPosition(posX, posY);
	initHPBar();
}
