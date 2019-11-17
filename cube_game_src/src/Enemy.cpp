#include "Enemy.h"

Enemy::Enemy() {
	// ...
}

void Enemy::init(sf::Vector2f size, sf::Vector2f position) {
	_MoveDirection = rand() % 4 + 1;
	_EnemyRect.setFillColor(sf::Color::Red);
	_EnemyRect.setSize(size);
	_EnemyRect.setPosition(position);
}

sf::FloatRect Enemy::enemyGetGlobalBounds() {
	return _EnemyRect.getGlobalBounds();
}

void Enemy::updateEnemy() {
	_moveEnemy();
}

void Enemy::drawTo(sf::RenderWindow &window) {
	window.draw(_EnemyRect);
}

void Enemy::_moveEnemy() {
	_EnemyTimeMs = _EnemyClock.getElapsedTime();
	if (_EnemyTimeMs.asMilliseconds() < 1500) {
		switch (_MoveDirection) {
		case 1:
			if(_EnemyRect.getPosition().x >= 770) {
				_MoveDirection = 2;
				_EnemyClock.restart();
				break;
			}
			else {
				_EnemyRect.move(1.0f, 0.0f);
				break;
			}
			break;
		case 2:
			if (_EnemyRect.getPosition().x <= 20) {
				_MoveDirection = 4;
				_EnemyClock.restart();
				break;
			}
			else {
				_EnemyRect.move(-1.0f, 0.0f);
				break;
			}
			break;
		case 3:
			if (_EnemyRect.getPosition().y >= 570) {
				_MoveDirection = 4;
				_EnemyClock.restart();
				break;
			}
			else {
				_EnemyRect.move(0.0f, 1.0f);
				break;
			}
			break;
		case 4:
			if (_EnemyRect.getPosition().y <= 10) {
				_MoveDirection = 3;
				_EnemyClock.restart();
				break;
			}
			else {
				_EnemyRect.move(0.0f, -1.0f);
				break;
			}
			break;
		default:
			// ...
			break;
		}
	}
	else {
		_EnemyClock.restart();
		_MoveDirection = rand() % 4 + 1;
	}
}

void Enemy::checkCollision(Player& player, sf::Text &text, std::ostringstream& sstr, bool &gameOver) {
	if (_EnemyRect.getGlobalBounds().intersects(player.playerGetGlobalBounds())) {
		sstr.str(""); 
		sstr << "Game Over!";
		text.setPosition(305, 250);
		text.setString(sstr.str());
		gameOver = true;
	}
}