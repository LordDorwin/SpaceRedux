//entity.h
//Header file for virtual Entity class

#pragma once

#include "SFML\Window.hpp"

#ifndef ENTITY_H
#define ENTITY_H

class sf::Window;

class Entity {
public:
	//Constructors/Destructors
	Entity() {};
	~Entity() {};

	//Code to be executed once per game loop
	virtual void update(int frameTime)=0;

	//Draw entity to designated window
	virtual void draw(sf::RenderWindow* window)=0;
};

#endif
