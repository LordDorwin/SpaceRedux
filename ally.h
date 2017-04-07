//ally.h

#pragma once

#ifndef ALLY_H
#define ALLY_H

#include "entity.h"

class Ally : public Entity {
public:

	//Constructors/Destructors
	Ally();
	Ally(int x, int y);
	~Ally();

	sf::Sprite sprite;
	sf::Texture texture;

	//Movement variables
	float turnSpeed = 0.00005f;
	float fThrust = 0.0000025f;
	float sThrust = 0.0000012f;
	float rThrust = 0.0000015f;
	float maxSpeed = 0.0001f;

	virtual float getx();
	virtual float gety();

	void setTar(Entity* target);

	//Code to be executed once per game loop
	virtual void update(int frameTime);

	//Draw entity to designated window
	virtual void draw(sf::RenderWindow* window);

	void thrLeft();
	void thrRight();
	void thrForward();
	void thrBack();

private:

	//Holds current speed on current heading
	float heaSpeed;

	//Heading and thrust vectors
	float heaVecX = 0, heaVecY = 0;
	float thrVecX = 0, thrVecY = 0;
	double heaDir;

	//Rotate ship towards target direction
	double rotate(double curDirection, double tarDirection);

	//Movement variables
	double direction;
	float _x = 0, _y = 0;
	double curDirection;
	double tarDirection;
	double turn;
	float getDirection;

	//Targeting variables
	Entity* target;
};

#endif