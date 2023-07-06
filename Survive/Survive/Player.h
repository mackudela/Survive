#pragma once

#include "Entity.h"

#define PLAYER_SPEED 20.f;

class Player : public Entity
{
public:
	Player();
	float getPlayerSpeed();
	void update();
	void render(sf::RenderTarget& target);
	void move(const float x, const float y);

private:
	sf::Sprite sprite;
	sf::Texture texture;
	const float playerSpeed = PLAYER_SPEED;

	void initVariables();
	 void initTexture();
	void initSprite();
};