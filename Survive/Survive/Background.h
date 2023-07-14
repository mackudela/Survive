#pragma once
#include "Entity.h"

class Background : public Entity {
public:

	Background();

private:

	void initTexture(std::string texturePath) override;
	void initSprite() override;
};