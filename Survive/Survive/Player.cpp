#include "Player.h"

#define PLAYER_TEXTURE_PATH "media/textures/hooman.png"

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

const sf::Vector2f Player::getPlayerPosition()
{
	return sprite.getPosition();
}

void Player::initTexture()
{
	if (!texture.loadFromFile(PLAYER_TEXTURE_PATH))
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

void Player::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}
