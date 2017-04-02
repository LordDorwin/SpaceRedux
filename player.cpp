//player.cpp
//Implementation file for player class

#include <cmath>
#include "player.h"
#include "globals.h"
#include "utility.h"
#include "scripts.h"


Player::Player(){

}

Player::Player(int x, int y){
	_x = x;
	_y = y;

	texture.loadFromFile("Sprites/player_ship.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.setOrigin(sf::Vector2f(22, 11.5));
}

Player::~Player(){

}

float Player::getx(){
	return _x;
}

float Player::gety(){
	return _y;
}

double Player::getDir()
{
	return prevDirection;
}

sf::Vector2f Player::getHea()
{
	return heading;
}

sf::Vector2f Player::getThr()
{
	return thrust;
}

float Player::getTurnSpeed()
{
	return turnSpeed;
}

float Player::getMaxSpeed()
{
	return maxSpeed;
}

void Player::update(int frameTime){

	//Calculate amount to rotate
	//Direction is used for movement, cur/tarDirection used for rotation
	prevDirection = (double)(sprite.getRotation());
	//tarDirection = pointDirection((int)_x, (int)_y, mouse::x, mouse::y);
	turn = scr::calcRotate(this) * frameTime; //keep me
	direction = prevDirection + turn;
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.rotate(turn);
	heading = scr::calcHeading(this, frameTime);
	
	//Move Ship
	_x += heading.x * frameTime;
	_y += heading.y * frameTime;
	

	//Reset thrust vectors
	thrust.x = 0;
	thrust.y = 0;
}

void Player::draw(sf::RenderWindow* window){
	window->draw(sprite);
}

void Player::thrLeft(){
	thrust.x += sThrust * cos(degRad(direction - 90));
	thrust.y += sThrust * sin(degRad(direction - 90));
}

void Player::thrRight(){
	thrust.x += sThrust * cos(degRad(direction + 90));
	thrust.y += sThrust * sin(degRad(direction + 90));
}

void Player::thrForward(){
	thrust.x += fThrust * cos(degRad(direction ));
	thrust.y += fThrust * sin(degRad(direction ));
}

void Player::thrBack(){
	thrust.x += rThrust * cos(degRad(direction + 180));
	thrust.y += rThrust * sin(degRad(direction + 180));
}
