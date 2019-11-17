#pragma once
#include "data.h"
#include "player.h"
class Coin
{
public:
	void init();
	void drawTo(sf::RenderWindow& window);
	void checkCollision(Player &player, int &score);
private:
	bool _active;
	sf::RectangleShape _coinRect;
};

