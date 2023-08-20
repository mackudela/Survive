#include "Player.h"

Player::Player() : playerSpeed(600.f), attackCooldown(sf::seconds(1.f))
{
	initTexture(texturePath);
	initSprite();
	cooldownTimer.restart();
}

float Player::getMovementSpeed()
{
	return playerSpeed;
}

void Player::render(sf::RenderTarget& target)
{
	//draw player
	target.draw(sprite);

	//draw player spells
	for (auto it = playerSpells.begin(); it != playerSpells.end();)
	{

		if (it->first->isAlive())
		{
			target.draw(it->first->getSprite());
			++it;
		}
		else
		{
			playerSpells.erase(it++);
		}
	}
}

void Player::attackSpell(sf::Vector2f direction)
{
	if (cooldownTimer.getElapsedTime().asSeconds() >= attackCooldown.asSeconds())
	{
		std::shared_ptr<SyringeAttack> syringeAttk = std::make_shared<SyringeAttack>(getCenterPosition().x, getCenterPosition().y, direction, 50.f);
		playerSpells.insert_or_assign(std::move(syringeAttk), "Syringe");
		cooldownTimer.restart();
	}
}

void Player::move(float x, float y)
{
	//Move player
	sprite.move(x, y);

	//Move player spells
	for (auto const& spell : playerSpells)
	{
		spell.first->move(spell.first->getDirection());
	}
}

std::unordered_map<std::shared_ptr<SyringeAttack>, std::string> Player::getPlayerSpells()
{
	return playerSpells;
}
	
void Player::destroySpell(std::shared_ptr<SyringeAttack> spell)
{	
	playerSpells.erase(playerSpells.find(spell));
}

