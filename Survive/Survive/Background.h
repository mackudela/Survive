#pragma once
#include "Entity.h"

const int g_backgroundWidth = 4000;
const int g_backgroundHeight = 4000;

class Background : public Entity 
{
public:
	Background();

private:
	const std::string texturePath = "media\\textures\\background.jpg";
	void initTexture(std::string texturePath) override;
	void initSprite() override;
};