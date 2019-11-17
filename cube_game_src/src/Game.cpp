#include "Game.h"

Game::Game() {

}

void Game::_init() {
	_gameOver = false;
	_score = 0;
	_lblSstr << "Score: " << _score;
	_lblFontArial.loadFromFile("fonts\\arial.ttf");
	_lblScore.setCharacterSize(30);
	_lblScore.setPosition(10, 10);
	_lblScore.setFont(_lblFontArial);
	_lblScore.setString(_lblSstr.str());
	for (int i = 0; i < NUMBER_OF_COINS; i++) {
		_coins[i].init();
	}
	for (int i = 0; i < NUMBER_OF_ENEMIES; i++) {
		_enemies[i].init({ 30, 30 }, {(float)(rand() % 700 + 100), (float)(rand() % 400 + 100)});
	}
}

void Game::_victory() {
	_lblSstr.str("");
	_lblSstr << "You won!";
	_lblScore.setPosition(325, 250);
	_lblScore.setString(_lblSstr.str());
	_gameOver = true;
}

void Game::_scoreCheck() {
	if (_score >= 100) {
		_victory();
	}
 }

void Game::_checkForInput()
{
	if (GetAsyncKeyState(VK_UP))
	{
		_player.MoveDirection = 'U';
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		_player.MoveDirection = 'D';
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		_player.MoveDirection = 'R';
	}
	else if (GetAsyncKeyState(VK_LEFT)) {
		_player.MoveDirection = 'L';
	}
	else {
		_player.MoveDirection = 'C';
	}
}

void Game::_updateWorld() {
	_lblSstr.str("");
	_lblSstr << "Score: " << _score;
	_lblScore.setString(_lblSstr.str());
	_player.checkForMovement();
	_scoreCheck();
	for (int i = 0; i < NUMBER_OF_ENEMIES; i++) {
		_enemies[i].updateEnemy();
		_enemies[i].checkCollision(_player, _lblScore, _lblSstr, _gameOver);
	}
	for (int i = 0; i < NUMBER_OF_COINS; i++) {
		_coins[i].checkCollision(_player, _score);
	}
}

void Game::_draw(sf::RenderWindow &window)
{
	_player.drawTo(window);
	for (int i = 0; i < NUMBER_OF_COINS; i++) {
		_coins[i].drawTo(window);
	}
	for (int i = 0; i < NUMBER_OF_ENEMIES; i++) {
		_enemies[i].drawTo(window);
	}
	window.draw(_lblScore);

}

void Game::start()
{
	srand(time(NULL));
	_init();
	RenderWindow app(VideoMode(GAME_WIDTH, GAME_HEIGHT), "Cube Game", Style::Titlebar | Style::Close);
	Event WINDOW_CLOSE_EVENT;
	while (app.isOpen())
	{
	    while (app.pollEvent(WINDOW_CLOSE_EVENT)) if (WINDOW_CLOSE_EVENT.type == Event::Closed) app.close();
		if (_gameOver != true) {
			_checkForInput();
			_updateWorld();
			app.clear(sf::Color::Blue);
			_draw(app);
			app.display();
			Sleep(FRAME_RATE);
		}
	}
}