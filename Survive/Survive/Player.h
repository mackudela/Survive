#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	float getMovementSpeed();

private:
	const std::string texturePath = "media\\textures\\hooman.png";
	const float playerSpeed = 600.f;
};