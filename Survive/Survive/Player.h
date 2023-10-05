#pragma once

#include <memory>
#include <unordered_map>

#include "Entity.h"
#include "SyringeAttack.h"
#include "RotatingGuardian.h"
#include "Animation.h"

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
	void setPosition(const float x, const float y);
	const sf::Vector2f getPosition();
	bool checkCollision(sf::FloatRect entity);
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getCenterPosition();
	sf::Vector2u getTextureSize();
	sf::Sprite getSprite();

private:
	void initRotatingGuardian();	
	void initAnimation();

	const std::string texturePath = "media\\textures\\player\\playerIdle.png";
	float playerSpeed;
	std::unordered_map<std::shared_ptr<Spell>, std::string> playerSpells;
	sf::Time attackCooldown;
	sf::Clock cooldownTimer;
	std::unique_ptr<Animation> animation;
};