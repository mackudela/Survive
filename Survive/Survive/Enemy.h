#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	float getMovementSpeed();
	void render(sf::RenderTarget& target) override;
	void move(sf::Vector2f direction) override;
	void receiveDamage(float damage);
	float getHP();
	float getXP();

protected:
	float currentHP;
	float maxHP;
	float XP;
	float movementSpeed;
	const std::string texturePath = "media\\textures\\enemy2.png";
	std::shared_ptr<sf::RectangleShape> hpBar;

	void initHPBar();
	void renderHPBar(sf::RenderTarget& target);
	void updateHpBar();
};