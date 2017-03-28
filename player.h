//player.h
//Header for player class

#pragma once

#include <SFML/Graphics.hpp>
#include "entity.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Entity{
public:
	
	//Constructors/Destructors
	Player();
	Player(int x, int y);
	~Player();

	sf::Sprite sprite;
	sf::Texture texture;

	//Movement variables
	float fThrust = 0.00000025f;
	float sThrust = 0.00000022f;
	float rThrust = 0.00000022f;
	float maxSpeed = 0.0001f;
	float turnSpeed = 0.1f;

	
	
	//Code to be executed once per game loop
	virtual void update(int frameTime);

	//Draw entity to designated window
	virtual void draw(sf::RenderWindow window);

	//Movement functions
	void thrLeft();
	void thrRight();
	void thrForward();
	void thrBack();

	//Rotate ship towards target direction
	double rotate(double curDirection, double tarDirection);

private:
	
	//Holds current speed on current heading
	float heaSpeed;

	//Position
	float _x = 0, _y = 0;

	//Heading and thrust vectors
	float heaVecX = 0, heaVecY = 0;
	float thrVecX = 0, thrVecY = 0;
	double heaDir;

	//Rotation variables
	double direction;
	double curDirection;
	double tarDirection;
	double turn;
	float getDirection;

};







#endif