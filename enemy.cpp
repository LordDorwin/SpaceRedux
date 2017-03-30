//enemy.cpp
//Implementation of enemy class

#include "enemy.h"
#include "utility.h"
#include "globals.h"

Enemy::Enemy(){

}

Enemy::Enemy(int x, int y){
	_x = x;
	_y = y;

	texture.loadFromFile("Sprites/enemy_ship.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.setOrigin(sf::Vector2f(22, 11.5));
}

Enemy::~Enemy(){

}

void Enemy::update(int frameTime){
	getDirection = sprite.getRotation();
	curDirection = (double)getDirection;
	tarDirection = pointDirection((int)_x, (int)_y, mouse::x, mouse::y);
	turn = rotate(curDirection, tarDirection);
	direction = getDirection + turn;
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.rotate(turn);
}

void Enemy::draw(sf::RenderWindow * window){
	window->draw(sprite);
}

double Enemy::rotate(double curDirection, double tarDirection){
	if (abs(curDirection - tarDirection) <2) {
		return 0;
	}
	else if (curDirection - tarDirection > abs(curDirection - (360 + tarDirection))) {
		if (curDirection - tarDirection > 0) {
			return turnSpeed;
		}
		else {
			return 0 - turnSpeed;
		}
	}
	else if (tarDirection > curDirection) {
		if (tarDirection - curDirection > 180) {
			return 0 - turnSpeed;
		}
		else {
			return turnSpeed;
		}
		return turnSpeed;
	}
	else if (tarDirection < curDirection) {
		return 0 - turnSpeed;
	}
	else
		return 0;
}
