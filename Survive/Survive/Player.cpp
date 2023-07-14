#include "Player.h"

#define PLAYER_TEXTURE_PATH "media/textures/hooman.png"

Player::Player()
{
	initTexture(PLAYER_TEXTURE_PATH);
	initSprite();
}

float Player::getMovementSpeed()
{
	return playerSpeed;
}
