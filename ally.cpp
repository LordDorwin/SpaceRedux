//ally.cpp

#include "Ally.h"
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

float Ally::getx() {
	return _x;
}

float Ally::gety() {
	return _y;
}

void Ally::update(int frameTime) {

	//Calculate amount to rotate
	//Direction is used for movement, cur/tarDirection used for rotation
	getDirection = sprite.getRotation();
	curDirection = (double)getDirection;
	tarDirection = pointDirection((int)_x, (int)_y, mouse::x, mouse::y);
	turn = rotate(curDirection, tarDirection) * frameTime;
	direction = getDirection + turn;
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.rotate(turn);

	//Only do heading calculations if thrust is being applied
	if (thrVecX != 0 || thrVecY != 0) {
		//Apply thrust
		heaVecX = heaVecX + thrVecX;
		heaVecY = heaVecY + thrVecY;

		//Calculate resulting heading
		heaSpeed = sqrt((heaVecX*heaVecX) + (heaVecY*heaVecY));
		heaDir = radDeg(acos(heaVecX / heaSpeed));

		//Limit speed
		if (heaSpeed > maxSpeed) {
			heaVecX = maxSpeed * abs(cos(degRad(heaDir))) * sign(heaVecX);
			heaVecY = maxSpeed * abs(sin(degRad(heaDir))) * sign(heaVecY);
		}
	}
	else {
		//Apply friction
		heaVecX += -globals::friction  * sign(heaVecX);
		heaVecY += -globals::friction  * sign(heaVecY);
	}

	//Move Ship
	_x += heaVecX * frameTime;
	_y += heaVecY * frameTime;


	//Reset thrust vectors
	thrVecX = 0;
	thrVecY = 0;
}

void Ally::draw(sf::RenderWindow* window) {
	window->draw(sprite);
}

void Ally::thrLeft() {
	thrVecX += sThrust * cos(degRad(direction - 90));
	thrVecY += sThrust * sin(degRad(direction - 90));
}

void Ally::thrRight() {
	thrVecX += sThrust * cos(degRad(direction + 90));
	thrVecY += sThrust * sin(degRad(direction + 90));
}

void Ally::thrForward() {
	thrVecX += fThrust * cos(degRad(direction));
	thrVecY += fThrust * sin(degRad(direction));
}

void Ally::thrBack() {
	thrVecX += rThrust * cos(degRad(direction + 180));
	thrVecY += rThrust * sin(degRad(direction + 180));
}

double Ally::rotate(double curDirection, double tarDirection) //this logic sucked so hard
{
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
		return 0; //I legit have no idea how you would get here but it wanted an emergency exit state
}
