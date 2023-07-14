#include "Background.h"

#define BACKGROUND_TEXTURE_PATH "media/textures/background.jpg"

Background::Background()
{
	initTexture(BACKGROUND_TEXTURE_PATH);
	initSprite();
}

void Background::initTexture(std::string texturePath)
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
