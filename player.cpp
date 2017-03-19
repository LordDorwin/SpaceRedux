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

void Player::update(){
	sprite.setPosition(sf::Vector2f(_x, _y));
}

void Player::thrLeft(){
	_x -= 1;
}

void Player::thrRight(){
	_x += 1;
}

void Player::thrForward(){
	_y -= 1;
}

void Player::thrBack(){
	_y += 1;
}

void Player::rotate(double tarDirection){
}
