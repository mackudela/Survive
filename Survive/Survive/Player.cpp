#include "Player.h"

Player::Player()
{
	this->initVariables();
}

void Player::initVariables()
{
	if (!texture.loadFromFile("media/textures/hooman.png"))
	{
		std::cout << "Could not load Player texture file\n";
	}
	this->setTexture(texture);
}

float Player::getPlayerSpeed()
{
	return this->playerSpeed;
}
