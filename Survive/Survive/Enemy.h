#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	float getMovementSpeed();
	void render(sf::RenderTarget& target) override;
	void move(sf::Vector2f direction) override;
protected:

private:
	int currentHP;
	int maxHP;
	float movementSpeed = 400.f;
	const std::string texturePath = "media\\textures\\enemy.png";
	sf::RectangleShape hpBar;

	void initHPBar();
	void renderHPBar(sf::RenderTarget& target);
	void updateHpBarPosition();
};