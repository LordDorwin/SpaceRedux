//player.h
//Header for player class

#pragma once

#include <SFML/Graphics.hpp>
#include "ally.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player{
public:
	
	//Constructors/Destructors
	Player();
	~Player();

	//Set the entity the player is controlling
	void setControl(Ally* ally);

	//Get information about controlled Entity
	float getx();
	float gety();
		
	//Affect an Ally Entity
	void thrLeft();
	void thrRight();
	void thrForward();
	void thrBack();


private:
	Ally* ally;
	
};


#endif