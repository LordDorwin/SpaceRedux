//group.h
//Header file for group class
//Allows multiple entities to be grouped together and updated/drawn at once.

#pragma once

#ifndef GROUP_H
#define GROUP_H

#include"entity.h"

#include<forward_list>

class Group {
public:
	//Constructors/Destructors
	Group();
	~Group();

	//Add entity to group
	void add(Entity* Ent);
	//Remove entity from group
	void remove(Entity* Ent);

	//Update and draw functions for whole group
	void update(int frameTime);
	void draw(sf::RenderWindow* window);

private:
	std::forward_list<Entity*> GrpList;
};

#endif