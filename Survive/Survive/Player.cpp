#include "Player.h"

Player::Player()
{
	initTexture(texturePath);
	initSprite();
}

float Player::getMovementSpeed()
{
	return playerSpeed;
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(sprite);
	for (auto const& spell : playerSpells)
	{
		target.draw(spell->getSprite());
	}
}

void Player::attackSpell(sf::Vector2f direction)
{
	std::unique_ptr<SyringeAttack> syringeAttk = std::make_unique<SyringeAttack>(getCenterPosition().x, getCenterPosition().y, direction);
	playerSpells.push_back(std::move(syringeAttk));
	//std::cout << "Syringe on\n";
}

void Player::move(float x, float y)
{
	sprite.move(x, y);
	for (auto const& spell : playerSpells)
	{
		spell->move(spell->getDirection());
		//std::cout << "spell cords: " << spell->getPosition().x << " " << spell->getPosition().y << "\n";
	}
}
