#include "Animation.h"

Animation::Animation(std::string texturePath, int numFrames, float frameDuration) :
	currentFrame(0), frameDuration(frameDuration), elapsedFrameTime(0.0f)
{
	initTexture(texturePath);
	sprite.setTexture(texture);
	int frameWidth = texture.getSize().x / numFrames;
	for (int i = 0; i < numFrames; ++i)
	{
		sf::IntRect frameRect(i * frameWidth, 0, frameWidth, texture.getSize().y);
		frames.push_back(frameRect);
	}
	sprite.setTextureRect(frames[currentFrame]);
}

void Animation::update(sf::Time dt)
{
	elapsedFrameTime += dt.asSeconds();
	if (elapsedFrameTime >= frameDuration)
	{
		currentFrame = (currentFrame + 1) % frames.size();
		sprite.setTextureRect(frames[currentFrame]);
		elapsedFrameTime = 0.0f;
	}
}

void Animation::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

sf::Vector2f Animation::getPosition()
{
	return sprite.getPosition();
}

void Animation::move(float x, float y, sf::Time dt)
{
	sprite.move(x, y);
	update(dt);
}

void Animation::draw(sf::RenderTarget& window)
{
	window.draw(sprite);
}

bool Animation::checkCollisions(sf::FloatRect entity)
{
	if (sprite.getGlobalBounds().intersects(entity))
		return true;
	return false;
}

sf::FloatRect Animation::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

sf::Vector2f Animation::getCenterPosition()
{
	sf::Vector2f position;
	position.x = sprite.getPosition().x + (frames[currentFrame].width / 2);
	position.y = sprite.getPosition().y + (frames[currentFrame].height / 2);
	return position;
}

sf::Vector2u Animation::getTextureSize()
{
	sf::Vector2u size;
	size.x = frames[currentFrame].width;
	size.y = frames[currentFrame].height;
	return size;
}

sf::Sprite Animation::getSprite()
{
	return sprite;
}

void Animation::initTexture(std::string texturePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		std::cout << "Could not load texture file\n";
	}
}
