#include "Player.h"

Player::Player()
{
	initTexture();
	initSprite();
	initVariables();
}

void Player::initVariables()
{

}

float Player::getPlayerSpeed()
{
	return playerSpeed;
}

void Player::initTexture()
{
	if (!texture.loadFromFile("media/textures/hooman.png"))
	{
		std::cout << "Could not load Player texture file\n";
	}
}

void Player::initSprite()
{
	sprite.setTexture(texture);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void Player::move(const float x, const float y)
{
	sprite.move(x, y);
}
