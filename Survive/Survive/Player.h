#pragma once

#include "Entity.h"

#define PLAYER_SPEED 300.f;

class Player : public Entity
{
public:
	Player();
	float getMovementSpeed();

private:
	sf::Sprite sprite;
	sf::Texture texture;
	const float playerSpeed = PLAYER_SPEED;
};