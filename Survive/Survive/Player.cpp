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

sf::Vector2f Player::getPlayerCenterPosition()
{
	sf::Vector2f position;
	position.x = sprite.getPosition().x + (getTextureSize().x / 2);
	position.y = sprite.getPosition().y + (getTextureSize().y / 2);
	return position;
}
