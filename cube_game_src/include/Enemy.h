#pragma once
#include "data.h"
#include "player.h"

class Enemy
{
public:
	Enemy();
	sf::FloatRect enemyGetGlobalBounds();
	void init(sf::Vector2f size, sf::Vector2f position);
	void updateEnemy();
	void drawTo(sf::RenderWindow &window);
	void checkCollision(Player &player, sf::Text &text, std::ostringstream &sstr, bool &gameOver);
private:
	int _MoveDirection;
	sf::Clock _EnemyClock;
	sf::Time _EnemyTimeMs;
	sf::RectangleShape _EnemyRect;
	void _moveEnemy();
};

