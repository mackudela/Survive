#include "Player.h"

Player::Player()
{
	initTexture(g_playerTexturePath);
	initSprite();
}

float Player::getMovementSpeed()
{
	return playerSpeed;
}

sf::Vector2u Player::getTextureSize()
{
	return texture.getSize();
}
