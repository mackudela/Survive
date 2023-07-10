#pragma once

#include "Entity.h"

#define PLAYER_SPEED 300.f;

class Player : public Entity
{
public:
	Player();
	float getPlayerSpeed();
	const sf::Vector2f getPlayerPosition();

	void update();
	void render(sf::RenderTarget& target);
	void move(const float x, const float y);
	void setPosition(const float x, const float y);

private:
	sf::Sprite sprite;
	sf::Texture texture;
	const float playerSpeed = PLAYER_SPEED;

	void initVariables();
	void initTexture();
	void initSprite();
};