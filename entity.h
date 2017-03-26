//entity.h
//Header file for virtual Entity class

#pragma once

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
	//Constructors/Destructors
	Entity();
	~Entity();

	//Code to be executed once per game loop
	void update(int frameTime);


private:
};

#endif
