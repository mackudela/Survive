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

void Entity::move(sf::Vector2f direction)
{
	sprite.move(direction);
}

void Entity::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}

void Entity::rotate(sf::Vector2f direction)
{
	sprite.rotate(atan2(direction.y, direction.x) * 180.f / (atan(1.f) * 4.f) + 90.f); // (atan(1) + 4) == pi
}

bool Entity::checkCollision(sf::FloatRect entity)
{
	if (sprite.getGlobalBounds().intersects(entity))
		return true;
	return false;
}

sf::FloatRect Entity::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

sf::Vector2f Entity::getCenterPosition()
{
	sf::Vector2f position;
	position.x = sprite.getPosition().x + (texture.getSize().x / 2);
	position.y = sprite.getPosition().y + (texture.getSize().y / 2);
	return position;
}

sf::Vector2u Entity::getTextureSize()
{
	return texture.getSize();
}
