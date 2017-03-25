//player.cpp
//Implementation file for player class

#include "player.h"
#include "globals.h"
#include "utility.h"
#include <cmath>


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

	//Calculate amount to rotate
	//Direction is used for movement, cur,tarDirection used for rotation
	getDirection = sprite.getRotation();
	curDirection = (double)getDirection; 
	tarDirection = pointDirection((int)_x, (int)_y, mouse::x, mouse::y);  
	turn = rotate(curDirection, tarDirection);
	direction = getDirection + turn; 
	//printf("%lf\n", direction);
	sprite.setPosition(sf::Vector2f(_x, _y));
	//sprite.setRotation(direction);
	sprite.rotate(turn);

	//Apply thrust
	printf("pre: %lf, %lf\n", heaVecX, heaVecY);
	heaVecX = (heaVecX) + thrVecX;
	heaVecY = (heaVecY) + thrVecY;
	printf("post: %lf, %lf\n", heaVecX, heaVecY);

	//Calculate resulting heading
	heaSpeed = sqrt((heaVecX*heaVecX) + (heaVecY*heaVecY));
	//calculate direction

	if (heaSpeed > maxSpeed) {
		//limit speed
	}

	//Move ship
	_x += heaVecX * frameTime;
	_y += heaVecY * frameTime;

	//Reset thrust vectors
	thrVecX = 0;
	thrVecY = 0;
}

void Player::thrLeft(){
	thrVecX += sThrust * cos(degRad(direction - 90));
	thrVecY += sThrust * sin(degRad(direction - 90));
}

void Player::thrRight(){
	thrVecX += sThrust * cos(degRad(direction + 90));
	thrVecY += sThrust * sin(degRad(direction + 90));
}

void Player::thrForward(){
	thrVecX += fThrust * cos(degRad(direction ));
	thrVecY += fThrust * sin(degRad(direction ));
}

void Player::thrBack(){
	thrVecX += rThrust * cos(degRad(direction + 180));
	thrVecY += rThrust * sin(degRad(direction + 180));
}

double Player::rotate(double curDirection, double tarDirection) //this logic sucked so hard
{
	if (abs(curDirection - tarDirection) <2) {
		return 0;
	} else if (curDirection - tarDirection > abs(curDirection - (360 + tarDirection))) {
		if (curDirection - tarDirection > 0) {
			return turnSpeed;
		} else {
			return 0 - turnSpeed;
		}
	} else if (tarDirection > curDirection){
		if (tarDirection - curDirection > 180) {
			return 0 - turnSpeed;
		} else {
			return turnSpeed;
		}
		return turnSpeed;
	} else if (tarDirection < curDirection) {
		return 0 - turnSpeed;
	}
	else
		return 0; //I legit have no idea how you would get here but it wanted an emergency exit state
}
