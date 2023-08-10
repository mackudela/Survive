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
	std::unique_ptr<SyringeAttack> syringeAttk = std::make_unique<SyringeAttack>(getCenterPosition().x, getCenterPosition().y);
	//SyringeAttack *syringeAttk = new SyringeAttack(getCenterPosition().x, getCenterPosition().y);
	playerSpells.push_back(std::move(syringeAttk));
	std::cout << "Syringe on\n";
}
