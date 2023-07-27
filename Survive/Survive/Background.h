#pragma once
#include "Entity.h"

const int g_backgroundWidth = 4000;
const int g_backgroundHeight = 4000;
const std::string g_backgroundTexturePath = "media\\textures\\background.jpg";

class Background : public Entity {
public:

	Background();

private:

	void initTexture(std::string texturePath) override;
	void initSprite() override;
};