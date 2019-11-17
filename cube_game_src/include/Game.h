#pragma once
#include "data.h"
#include "Player.h"
#include "Enemy.h"
#include "Coin.h"

#define GAME_WIDTH 800
#define GAME_HEIGHT 600
#define FRAME_RATE 8
#define NUMBER_OF_COINS 20
#define NUMBER_OF_ENEMIES 20

class Game
{
public:
	Game();
	void start();
private:
    int _score;
	bool _gameOver;
	sf::Text _lblScore;
	sf::Font _lblFontArial;
	std::ostringstream _lblSstr;
	Player _player = Player({ 30, 30 }, { 30, 400 });
	Enemy _enemies[NUMBER_OF_COINS];
	Coin _coins[NUMBER_OF_COINS];
	void _init();
	void _victory();
	void _scoreCheck();
	void _checkForInput();
	void _draw(sf::RenderWindow& window);
	void _updateWorld();
};

