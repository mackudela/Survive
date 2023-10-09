#pragma once
#include "Enemy.h"
#include "Animation.h"

class FluVirus : public Enemy
{
public:
	FluVirus(float posX, float posY);
	void render(sf::RenderTarget& target) override;
	void move(sf::Vector2f direction, sf::Time deltaTime) override;
	sf::Vector2f getCenterPosition() override;
	sf::FloatRect getGlobalBounds() override;

private:
	void initAnimation();
	void updateHpBar() override;

	const std::string texturePath = "media\\textures\\FluVirus.png";
	std::unique_ptr<Animation> animation;
};