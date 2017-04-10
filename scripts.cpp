//scripts.cpp
//code that is used accross multiple classes

#include <cmath>
#include "scripts.h"
#include "globals.h"
#include "utility.h"



//rotate 
double scr::calcRotate(Entity* Ent){
	double prevDirection = Ent->getDir();
	double tarDirection = pointDirection((int)Ent->getx(), (int)Ent->gety(), Ent->getTar()->gety(), Ent->getTar()->gety());
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

//Calculates the heading for the current frame
sf::Vector2f scr::calcHeading(Entity* Ent, int frameTime){
	sf::Vector2f heading = Ent->getHea();
	sf::Vector2f thrust = Ent->getThr();
	double direction = Ent->getDir();
	float maxSpeed = Ent->getMaxSpeed();

	//Only do heading calculations if thrust is being applied
	if (thrust.x != 0 || thrust.y != 0) {
		//Apply thrust
		heading.x = heading.x + thrust.x;
		heading.y = heading.y + thrust.y;

		//Calculate resulting heading
		float heaSpeed = sqrt((heading.x*heading.x) + (heading.y*heading.y));
		double heaDir = radDeg(acos(heading.x / heaSpeed));

		//Limit speed
		if (heaSpeed > maxSpeed) {
			heading.x = maxSpeed * abs(cos(degRad(heaDir))) * sign(heading.x);
			heading.y = maxSpeed * abs(sin(degRad(heaDir))) * sign(heading.y);
		}
	}
	else {
		//Apply friction
		heading.x += -globals::friction  * sign(heading.x);
		heading.y += -globals::friction  * sign(heading.y);
	}

	return heading;
}