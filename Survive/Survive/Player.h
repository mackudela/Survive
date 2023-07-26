#pragma once

#include "Entity.h"

#define PLAYER_SPEED 1000.f;

class Player : public Entity
{
public:
	Player();
	float getMovementSpeed();
	sf::Vector2u getTextureSize();

private:
	const float playerSpeed = PLAYER_SPEED;
};