#pragma once

#include <unordered_map>
#include "Enemy.h"
#include "RedVirus.h"
#include "FluVirus.h"

class EnemySpawner 
{
public:
	EnemySpawner();
	void render(sf::RenderTarget& target);
	void spawnEnemies();
	void moveEnemies(sf::Time deltaTime, sf::Vector2f playerPosition);
	std::unordered_map<std::shared_ptr<Enemy>, std::string> getEnemies();
	void destroyEnemy(std::shared_ptr<Enemy> enemy);

private:
	sf::Clock gameClock;
	sf::Time spawnCooldown;
	sf::Clock spawnTimer;
	std::unordered_map<std::shared_ptr<Enemy>, std::string> enemies;

	sf::Vector2f normalizeVector(sf::Vector2f vector);
};