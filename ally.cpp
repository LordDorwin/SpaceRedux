//ally.cpp

#include "ally.h"
#include "globals.h"
#include "utility.h"
#include <cmath>


Ally::Ally() {

}

Ally::Ally(int x, int y) {
	_x = x;
	_y = y;

	texture.loadFromFile("Sprites/player_ship.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.setOrigin(sf::Vector2f(22, 11.5));
}

Ally::~Ally() {

}

float Ally::getx()
{
	return _x;
}

float Ally::gety()
{
	return _y;
}

void Ally::setTar(Entity * target) {
	this->target = target;
}

void Ally::update(int frameTime) {
	getDirection = sprite.getRotation();
	curDirection = (double)getDirection;
	tarDirection = pointDirection((int)_x, (int)_y, target->getx(), target->gety());
	turn = rotate(curDirection, tarDirection) * frameTime;
	direction = getDirection + turn;
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.rotate(turn);
}

void Ally::draw(sf::RenderWindow * window) {
	window->draw(sprite);
}

double Ally::rotate(double curDirection, double tarDirection) {
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
