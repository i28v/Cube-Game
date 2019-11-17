#include "Coin.h"

void Coin::init() {
	_active = true;
	_coinRect.setFillColor(sf::Color::Yellow);
	_coinRect.setSize({ 15, 15 });
	_coinRect.setPosition({ (float)(rand() % 750 + 1), (float)(rand() % 500 + 1) });
}

void Coin::drawTo(sf::RenderWindow& window) {
	if (_active == true) {
		window.draw(_coinRect);
	}
}

void Coin::checkCollision(Player& player, int &score) {
	if (_active == true) {
		if (_coinRect.getGlobalBounds().intersects(player.playerGetGlobalBounds())) {
			_active = false;
			score += 5;
		}
	}
}