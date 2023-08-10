#pragma once

#include "Entity.h"

class SyringeAttack : public Entity
{
public:
	SyringeAttack(float posX, float posY);
	sf::Sprite getSprite();

private:
	const std::string texturePath = "media\\textures\\syringe.png";

};