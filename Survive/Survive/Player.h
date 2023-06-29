#pragma once

#include "Entity.h"

#define PLAYER_SPEED 100.f;

class Player : public Entity
{
public:
	Player();
	void initVariables();
	float getPlayerSpeed();

private:
	sf::Texture texture;
	const float playerSpeed = PLAYER_SPEED;
};