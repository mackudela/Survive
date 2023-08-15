#pragma once
#include <memory>

#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "SyringeAttack.h"

const float g_viewCenterX = 960.f;
const float g_viewCenterY = 540.f;

class Game
{ 
public:
	Game();
	~Game();
	void run();

private:
	//inits
	void initWindow();
	void initView();
	void initBackground();
	void initPlayer();
	void initEnemy();
	//void initFont();

	//updates
	void processEvents();
	void update(sf::Time time);
	void updatePlayerMovement(sf::Time deltaTime);
	sf::Vector2f calculatePlayerMovement();
	void updateEnemyMovement(sf::Time deltaTime);
	sf::Vector2f normalizeVector(sf::Vector2f vector);
	void updateViewPosition();
	sf::Vector2f calculateViewPosition();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	//others
	void playerAttackSpell(sf::Vector2i mouseCords);

	std::unique_ptr<sf::RenderWindow> mainWindow;
	std::unique_ptr<sf::View> mainView;
	std::unique_ptr<Player> player;
	std::unique_ptr<Background> background;
	std::unique_ptr<Enemy> enemy;
	
	const std::string fontPath = "media\\fonts\\ARIAL.ttf";
	bool isMovingUp;
	bool isMovingDown;
	bool isMovingLeft;
	bool isMovingRight;
	float playerMovementSpeed;
	sf::Vector2f playerPosition;
	const sf::Time timePerFrame = sf::seconds(1.f / 144.f);
	//sf::Text playerPositionText;
	//std::string playerPositionString;
	//sf::Font font;
};