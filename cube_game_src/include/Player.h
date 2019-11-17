#pragma once
#include "data.h"

class Player
{
public:
	Player(sf::Vector2f size, sf::Vector2f position);
	sf::FloatRect playerGetGlobalBounds();
	void checkForMovement();
	void drawTo(RenderWindow& window);
	char MoveDirection;
	

private:
	void _movePlayer(char direction);
	int _health;
	int _level;
	sf::RectangleShape _PlayerRect;
};

