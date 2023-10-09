#include "Player.h"

Player::Player() : playerSpeed(400.f), attackCooldown(sf::seconds(1.f))
{
	initAnimation();
	cooldownTimer.restart();

	initRotatingGuardian();
}

float Player::getMovementSpeed()
{
	return playerSpeed;
}

void Player::render(sf::RenderTarget& target)
{
	//draw player
	animation->draw(target);

	//draw player spells
	for (auto it = playerSpells.begin(); it != playerSpells.end();)
	{
		if (it->second == "Syringe")
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
		else if ((it->second == "RotatingGuardian"))
		{
			target.draw(it->first->getSprite());
			++it;
		}
	}
}

void Player::attackSpell(sf::Vector2f direction)
{
	if (cooldownTimer.getElapsedTime().asSeconds() >= attackCooldown.asSeconds())
	{
		std::shared_ptr<SyringeAttack> syringeAttk = std::make_shared<SyringeAttack>(getCenterPosition().x, getCenterPosition().y, direction, 500.f, 50.f);
		playerSpells.insert_or_assign(std::move(syringeAttk), "Syringe");
		cooldownTimer.restart();
	}
}

void Player::move(float x, float y, sf::Time deltaTime)
{
	//Move player
	animation->move(x, y, deltaTime);

	//Move player spells
	for (auto const& spell : playerSpells)
	{
		if (spell.second == "Syringe")
		{
			spell.first->move(spell.first->getDirection() * deltaTime.asSeconds() * spell.first->getSpeed());
		}
		else if (spell.second == "RotatingGuardian")
		{
			spell.first->move(getCenterPosition().x, getCenterPosition().y);
		}
	}
}

std::unordered_map<std::shared_ptr<Spell>, std::string> Player::getPlayerSpells()
{
	return playerSpells;
}
	
void Player::destroySpell(std::shared_ptr<Spell> spell)
{	
	playerSpells.erase(playerSpells.find(spell));
}

void Player::setPosition(const float x, const float y)
{
	animation->setPosition(x, y);
}

const sf::Vector2f Player::getPosition()
{
	return animation->getPosition();
}

bool Player::checkCollision(sf::FloatRect entity)
{
	return animation->checkCollisions(entity);
}

sf::FloatRect Player::getGlobalBounds()
{
	return animation->getGlobalBounds();
}

sf::Vector2f Player::getCenterPosition()
{
	return animation->getCenterPosition();
}

sf::Vector2u Player::getTextureSize()
{
	return animation->getTextureSize();
}

sf::Sprite Player::getSprite()
{
	return animation->getSprite();
}

void Player::initRotatingGuardian()
{
	std::shared_ptr<RotatingGuardian> spell = std::make_shared<RotatingGuardian>(0.01f);
	playerSpells.insert_or_assign(std::move(spell), "RotatingGuardian");
}

void Player::initAnimation()
{
	animation = std::make_unique<Animation>(texturePath, 38, 0.2f);
}
