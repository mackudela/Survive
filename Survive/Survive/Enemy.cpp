#include "Enemy.h"

Enemy::Enemy() : isAlive(true)
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
	//hpBar.setScale(sf::Vector2f(0.5, 1));
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
	updateHpBar();
}

void Enemy::receiveDamage(int damage)
{
	currentHP -= damage;
}

int Enemy::getHP()
{
	return currentHP;
}

void Enemy::updateHpBar()
{
	hpBar.setPosition(getCenterPosition() - sf::Vector2f(hpBar.getSize().x / 2, (getTextureSize().y / 2) + 10.f));
}
