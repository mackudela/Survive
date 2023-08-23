#include "RotatingGuardian.h"

RotatingGuardian::RotatingGuardian(float speed)
{
	this->speed = speed;
	this->counter = 0.f;
	this->radius = 150.f;

	initTexture(texturePath);
	initSprite();
	sprite.setOrigin((sf::Vector2f)texture.getSize() / 2.f);
	sprite.setScale(0.6, 0.6);
}

void RotatingGuardian::move(const float playerPosX, const float playerPosY)
{
	sprite.setPosition(playerPosX + radius * sin(counter), playerPosY + radius * cos(counter));
	counter += speed;
	std::cout << counter << "\n";
	if (counter >= 6.3f)
	{
		counter = 0.f;
	}
}