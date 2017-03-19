//player.cpp
//Implementation file for player class

#include "player.h"


Player::Player(float x, float y){
	_x = x;
	_y = y;

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
	_dx = -1;
}

void Player::thrRight(){
	_dx = 1;
}

void Player::thrForward(){
	_dy = -1;
}

void Player::thrBack(){
	_dy = 1;
}

void Player::rotate(double tarDirection){
}
