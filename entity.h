//entity.h
//Header file for virtual Entity class

#pragma once

#include "SFML\Graphics.hpp"

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
	//Constructors/Destructors
	Entity() {};
	~Entity() {};

	//Code to be executed once per game loop
	virtual void update(int frameTime)=0;

	//Draw entity to designated window
	virtual void draw(sf::RenderWindow* window)=0;

	//Entity position
	virtual float getx() = 0;
	virtual float gety() = 0;

	//Entity direction
	virtual double getDir() = 0;

	//Entity thrust
	virtual sf::Vector2f getThr() = 0;

	//Entity heading
	virtual sf::Vector2f getHea() = 0;

	//Entity turn speed
	virtual float getTurnSpeed() = 0;

	//Entity max speed
	virtual float getMaxSpeed() = 0;
};

#endif
