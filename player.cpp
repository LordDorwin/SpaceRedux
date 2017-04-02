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
	//vector 

	////Only do heading calculations if thrust is being applied
	//if (thrust.x != 0 || thrust.y != 0) {
	//	//Apply thrust
	//	heading.x = heading.x+(thrust.x / frameTime);
	//	heading.y = heading.y+(thrust.y / frameTime);

	//	//Calculate resulting heading
	//	heaSpeed = sqrt((heading.x*heading.x) + (heading.y*heading.y));
	//	heaDir = radDeg(acos(heading.x / heaSpeed));

	//	//Limit speed
	//	if (heaSpeed > maxSpeed) {
	//		heading.x = maxSpeed * abs(cos(degRad(heaDir))) * sign(heading.x);
	//		heading.y = maxSpeed * abs(sin(degRad(heaDir))) * sign(heading.y);
	//	}
	//} else {
	//	//Apply friction
	//	heading.x += -globals::friction  * sign(heading.x);
	//	heading.y += -globals::friction  * sign(heading.y);
	//}

	//keep past here
	
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

//double Player::rotate(double curDirection, double tarDirection) //this logic sucked so hard
//{
//	if (abs(curDirection - tarDirection) <2) {
//		return 0;
//	} else if (curDirection - tarDirection > abs(curDirection - (360 + tarDirection))) {
//		if (curDirection - tarDirection > 0) {
//			return turnSpeed;
//		} else {
//			return 0 - turnSpeed;
//		}
//	} else if (tarDirection > curDirection){
//		if (tarDirection - curDirection > 180) {
//			return 0 - turnSpeed;
//		} else {
//			return turnSpeed;
//		}
//		return turnSpeed;
//	} else if (tarDirection < curDirection) {
//		return 0 - turnSpeed;
//	}
//	else
//		return 0; //I legit have no idea how you would get here but it wanted an emergency exit state
//}
