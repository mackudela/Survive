#include "FluVirus.h"

FluVirus::FluVirus(float posX, float posY)
{
	XP = 10.f;
	currentHP = maxHP = 100.f;
	movementSpeed = 250.f;

	initAnimation();
	animation->setPosition(posX, posY);
	initHPBar();
}

void FluVirus::render(sf::RenderTarget& target)
{
	animation->draw(target);
	renderHPBar(target);
}

void FluVirus::move(sf::Vector2f direction, sf::Time deltaTime)
{
	animation->move(direction, deltaTime);
	updateHpBar();
}

sf::Vector2f FluVirus::getCenterPosition()
{
	return animation->getCenterPosition();
}

sf::FloatRect FluVirus::getGlobalBounds()
{
	return animation->getGlobalBounds();
}

void FluVirus::initAnimation()
{
	animation = std::make_unique<Animation>(texturePath, 44, 0.2f);
}

void FluVirus::updateHpBar()
{
	hpBar->setPosition(getCenterPosition() - sf::Vector2f(hpBar->getSize().x / 2, (animation->getTextureSize().y / 2) + 10.f));
	hpBar->setScale(sf::Vector2f(currentHP / maxHP, 1));
}
