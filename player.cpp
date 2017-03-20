//player.cpp
//Implementation file for player class

#include "player.h"


Player::Player(float x, float y){
	_x = x;
	_y = y;
	_playerSpeed = 0.001;

	texture.loadFromFile("Sprites/player.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(_x, _y));
}

Player::~Player(){

}

void Player::update(int frameTime){
	_x += _dx * frameTime;
	_y += _dy * frameTime;
	sprite.setPosition(sf::Vector2f(_x, _y));
	_dx = 0, _dy = 0;
}

void Player::thrLeft(){
	_dx = -_playerSpeed;
}

void Player::thrRight(){
	_dx = _playerSpeed;
}

void Player::thrForward(){
	_dy = -_playerSpeed;
}

void Player::thrBack(){
	_dy = _playerSpeed;
}

void Player::rotate(double tarDirection){
}
