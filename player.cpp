//player.cpp
//Implementation file for player class

#include "player.h"
#include "globals.h"
#include "utility.h"


Player::Player(int x, int y){
	_x = x;
	_y = y;

	texture.loadFromFile("Sprites/player.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.setOrigin(sf::Vector2f(9.5, 4.5));
}

Player::~Player(){

}

void Player::update(int frameTime){
	direction = pointDirection((int)_x, (int)_y, mouse::x, mouse::y);
	printf("%lf\n", direction);
	_x += _dx * frameTime;
	_y += _dy * frameTime;
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.setRotation(direction);
	_dx = 0, _dy = 0;
}

void Player::thrLeft(){
	_dx = -sThrust;
	printf("%lf\n", _dx);
}

void Player::thrRight(){
	_dx = sThrust;
}

void Player::thrForward(){
	_dy = -fThrust;
}

void Player::thrBack(){
	_dy = rThrust;
}

void Player::rotate(double tarDirection){
}
