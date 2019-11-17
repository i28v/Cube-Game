#include "Player.h"

Player::Player(Vector2f size, Vector2f position)
{
	_PlayerRect.setFillColor(sf::Color::Green);
	_PlayerRect.setSize(size);
	_PlayerRect.setPosition(position);
}

sf::FloatRect Player::playerGetGlobalBounds() {
	return _PlayerRect.getGlobalBounds();
}

void Player::_movePlayer(char direction)
{
	switch (direction) {
	case 'U':
		if(!(_PlayerRect.getPosition().y <= 0)) _PlayerRect.move(0.0f, -2.0f);
		break;
	case 'D':
		if (!(_PlayerRect.getPosition().y >= 570)) _PlayerRect.move(0.0f, 2.0f);
		break;
	case 'R':
		if (!(_PlayerRect.getPosition().x >= 770)) _PlayerRect.move(2.0f, 0.0f);
		break;
	case 'L':
		if (!(_PlayerRect.getPosition().x <= 0)) _PlayerRect.move(-2.0f, 0.0f);
		break;
	default:
		break;
	}

}

void Player::checkForMovement() {
	switch (MoveDirection) {
	case 'U':
		_movePlayer('U');
		break;
	case 'D':
		_movePlayer('D');
		break;
	case 'R':
		_movePlayer('R');
		break;

	case 'L':
		_movePlayer('L');
		break;
	default:
		break;
		
	}
		
}
	
void Player::drawTo(RenderWindow& window)
{
	window.draw(_PlayerRect);
}
