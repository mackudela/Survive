#include "Entity.h"

const sf::Vector2f Entity::getPosition()
{
	return sprite.getPosition();
}

void Entity::initTexture(std::string texturePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		std::cout << "Could not load texture file\n";
	}
}

void Entity::initSprite()
{
	sprite.setTexture(texture);
}

void Entity::update()
{
}

void Entity::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void Entity::move(const float x, const float y)
{
	sprite.move(x, y);
}

void Entity::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}
