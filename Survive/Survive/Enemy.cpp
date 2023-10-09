#include "Enemy.h"

Enemy::Enemy() : XP(10.f), currentHP(100.f), maxHP(100.f), movementSpeed(250.f)
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
	hpBar = std::make_shared<sf::RectangleShape>();
	hpBar->setSize(sf::Vector2f(70.f, 7.f));
	hpBar->setFillColor(sf::Color::Red);
	hpBar->setOutlineThickness(1);
	hpBar->setOutlineColor(sf::Color::Black);
	hpBar->setPosition(getCenterPosition());
}

void Enemy::renderHPBar(sf::RenderTarget& target)
{
	target.draw(*hpBar);
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

void Enemy::move(sf::Vector2f direction, sf::Time dt)
{
	sprite.move(direction * movementSpeed * dt.asSeconds());
	updateHpBar();
}

void Enemy::receiveDamage(float damage)
{
	currentHP -= damage;
}

float Enemy::getHP()
{
	return currentHP;
}

float Enemy::getXP()
{
	return XP;
}

sf::Vector2f Enemy::getCenterPosition() 
{
	sf::Vector2f position;
	position.x = sprite.getPosition().x + (texture.getSize().x / 2);
	position.y = sprite.getPosition().y + (texture.getSize().y / 2);
	return position;
}

sf::FloatRect Enemy::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

void Enemy::updateHpBar()
{
	hpBar->setPosition(getCenterPosition() - sf::Vector2f(hpBar->getSize().x / 2, (getTextureSize().y / 2) + 10.f));
	hpBar->setScale(sf::Vector2f(currentHP / maxHP, 1));
}
