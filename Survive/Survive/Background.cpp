#include "Background.h"

#define BACKGROUND_TEXTURE_PATH "media/textures/background.jpg"

Background::Background()
{
	initTexture();
	initSprite();
}

void Background::update()
{
}

void Background::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void Background::move(const float x, const float y)
{
	sprite.move(x, y);
}

void Background::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}

void Background::initTexture()
{
	if (!texture.loadFromFile(BACKGROUND_TEXTURE_PATH))
	{
		std::cout << "Could not load background texture file\n";
	}
	texture.setRepeated(true);
}

void Background::initSprite()
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 4000, 4000));
}
