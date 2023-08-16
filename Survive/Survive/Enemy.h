#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	float getMovementSpeed();
	void render(sf::RenderTarget& target) override;
	void move(sf::Vector2f direction) override;
	void receiveDamage(int damage);
	int getHP();

protected:

private:
	int currentHP = 100;
	int maxHP;
	bool isAlive;
	float movementSpeed = 400.f;
	const std::string texturePath = "media\\textures\\enemy.png";
	sf::RectangleShape hpBar;

	void initHPBar();
	void renderHPBar(sf::RenderTarget& target);
	void updateHpBar();
};