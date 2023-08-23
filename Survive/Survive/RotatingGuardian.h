#pragma once

#include "Spell.h"

class RotatingGuardian : public Spell
{
public:
	RotatingGuardian(float speed);
	void move(const float playerPosX, const float playerPosY) override;

private:
	const std::string texturePath = "media\\textures\\WhiteBloodCell.png";
	float counter;
	float radius;
};