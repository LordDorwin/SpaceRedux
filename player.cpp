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
	turn = Player::calcRotate(this) * frameTime; //keep me
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

Entity * Player::getTar(){
	//Change me once ship switching is implemented
	return this;
}

double Player::calcRotate(Entity* Ent) {
	double prevDirection = Ent->getDir();
	double tarDirection = pointDirection((int)Ent->getx(), (int)Ent->gety(), mouse::x, mouse::y);
	float turnSpeed = Ent->getTurnSpeed();

	if (abs(prevDirection - tarDirection) <2) {
		return 0;
	}
	else if (prevDirection - tarDirection > abs(prevDirection - (360 + tarDirection))) {
		if (prevDirection - tarDirection > 0) {
			return turnSpeed;
		}
		else {
			return 0 - turnSpeed;
		}
	}
	else if (tarDirection > prevDirection) {
		if (tarDirection - prevDirection > 180) {
			return 0 - turnSpeed;
		}
		else {
			return turnSpeed;
		}
		return turnSpeed;
	}
	else if (tarDirection < prevDirection) {
		return 0 - turnSpeed;
	}
	else
		return 0; //must have exit state
}