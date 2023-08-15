#include "Enemy.h"

Enemy::Enemy()
{
	initTexture(texturePath);
	initSprite();
	initHPBar();
}

float Enemy::getMovementSpeed()
{
	return movementSpeed;
}

void Enemy::initHPBar()
{
	hpBar.setSize(sf::Vector2f(70.f, 7.f));
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setOutlineThickness(1);
	hpBar.setOutlineColor(sf::Color::Black);
	hpBar.setPosition(getCenterPosition());
}

void Enemy::renderHPBar(sf::RenderTarget& target)
{
	target.draw(hpBar);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(sprite);
	renderHPBar(target);
}

void Enemy::move(sf::Vector2f direction)
{
	sprite.move(direction);
	updateHpBarPosition();
}

void Enemy::updateHpBarPosition()
{
	hpBar.setPosition(getCenterPosition() - sf::Vector2f(hpBar.getSize().x / 2, (getTextureSize().y / 2) + 10.f));
}
