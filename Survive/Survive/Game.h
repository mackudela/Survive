#pragma once
#include <memory>

#include "Player.h"
#include "Background.h"
#include "Enemy.h"

const float g_viewCenterX = 960.f;
const float g_viewCenterY = 540.f;
const std::string g_fontPath = "media\\fonts\\ARIAL.ttf";

class Game
{ 
public:

	Game();
	~Game();
	void run();

private:

	void initWindow();
	void initView();
	void initBackground();
	void initPlayer();
	void initEnemy();
	void initFont();
	void processEvents();
	void update(sf::Time time);
	void updatePlayerMovement(sf::Time deltaTime);
	void updateEnemyMovement(sf::Time deltaTime);
	sf::Vector2f normalizeVector(sf::Vector2f vector);
	void updateViewPosition();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	std::unique_ptr<sf::RenderWindow> mainWindow;
	std::unique_ptr<sf::View> mainView;
	std::unique_ptr<Player> player;
	std::unique_ptr<Background> background;
	std::unique_ptr<Enemy> enemy;
	

	bool isMovingUp;
	bool isMovingDown;
	bool isMovingLeft;
	bool isMovingRight;
	float playerMovementSpeed;
	sf::Vector2f playerPosition;
	const sf::Time timePerFrame = sf::seconds(1.f / 144.f);
	sf::Text playerPositionText;
	std::string playerPositionString;
	sf::Font font;
};