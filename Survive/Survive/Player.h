#pragma once

#include <memory>

#include "Entity.h"
#include "SyringeAttack.h"

class Player : public Entity
{
public:
	Player();
	float getMovementSpeed();
	void render(sf::RenderTarget& target) override;
	void attackSpell(sf::Vector2f direction);
	void move(float x, float y) override;

private:
	const std::string texturePath = "media\\textures\\hooman.png";
	const float playerSpeed = 600.f;
	std::vector<std::unique_ptr<SyringeAttack>> playerSpells;

};