#pragma once

#include "Entity.h"

const float g_playerSpeed = 600.f;
const std::string g_playerTexturePath = "media\\textures\\hooman.png";

class Player : public Entity
{
public:
	Player();
	float getMovementSpeed();
	sf::Vector2u getTextureSize();
	sf::Vector2f getPlayerCenterPosition();

private:
	const float playerSpeed = g_playerSpeed;
};