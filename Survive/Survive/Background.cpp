#include "Background.h"

Background::Background()
{
	initTexture(g_backgroundTexturePath);
	initSprite();
}

void Background::initTexture(std::string texturePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		std::cout << "Could not load background texture file\n";
	}
	texture.setRepeated(true);
}

void Background::initSprite()
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, g_backgroundWidth, g_backgroundHeight));
}
