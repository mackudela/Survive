#include "Entity.h"

void Entity::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

void Entity::setVelocity(float velocityX, float velocityY)
{
	velocity.x = velocityX;
	velocity.y = velocityY;
}

sf::Vector2f Entity::getVelocity() const
{
	return velocity;
}
