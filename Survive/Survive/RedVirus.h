#pragma once

#include "Enemy.h"

class RedVirus : public Enemy
{
public:
	RedVirus(float posX, float posY);

private:
	const std::string texturePath = "media\\textures\\RedVirus.png";
};