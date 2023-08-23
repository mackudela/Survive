#pragma once

#include <memory>
#include <unordered_map>

#include "Entity.h"
#include "SyringeAttack.h"
#include "RotatingGuardian.h"

class Player : public Entity
{
public:
	Player();
	float getMovementSpeed();
	void render(sf::RenderTarget& target) override;
	void attackSpell(sf::Vector2f direction);
	void move(float x, float y, sf::Time deltaTime);
	std::unordered_map<std::shared_ptr<Spell>, std::string> getPlayerSpells();
	void destroySpell(std::shared_ptr<Spell> spell);

private:
	const std::string texturePath = "media\\textures\\hooman.png";
	float playerSpeed;
	std::unordered_map<std::shared_ptr<Spell>, std::string> playerSpells;
	sf::Time attackCooldown;
	sf::Clock cooldownTimer;

	void initRotatingGuardian();
};