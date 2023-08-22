#include "EnemySpawner.h"

EnemySpawner::EnemySpawner() : spawnCooldown(sf::seconds(1.f))
{
	gameClock.restart();
	spawnTimer.restart();
}

void EnemySpawner::render(sf::RenderTarget& target)
{
	for (auto it = enemies.begin(); it != enemies.end();)
	{
		it->first->render(target);
		++it;
	}
}

void EnemySpawner::spawnEnemies()
{
	if (spawnTimer.getElapsedTime().asSeconds() > spawnCooldown.asSeconds())
	{
		std::shared_ptr<RedVirus> enemy = std::make_shared<RedVirus>(100, 100);
		enemies.insert_or_assign(std::move(enemy), "Enemy");
		spawnTimer.restart();
	}
}

void EnemySpawner::moveEnemies(sf::Time deltaTime, sf::Vector2f playerPosition)
{
	for (auto const& enemy : enemies)
	{
		sf::Vector2f direction = playerPosition - enemy.first->getCenterPosition();
		direction = normalizeVector(direction);
		enemy.first->move(direction * deltaTime.asSeconds() * enemy.first->getMovementSpeed());
	}
}

std::unordered_map<std::shared_ptr<Enemy>, std::string> EnemySpawner::getEnemies()
{
	return enemies;
}

sf::Vector2f EnemySpawner::normalizeVector(sf::Vector2f vector)
{
	float magnitude = sqrtf(vector.x * vector.x + vector.y * vector.y);
	if (magnitude != 0)
	{
		vector.x /= magnitude;
		vector.y /= magnitude;
	}
	return vector;
}
