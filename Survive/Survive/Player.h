#pragma once

#include <memory>
#include <unordered_map>

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
	std::unordered_map<std::unique_ptr<SyringeAttack>, std::string> playerSpells;
};