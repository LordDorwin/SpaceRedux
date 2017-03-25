//player.h
//Header for player class

#pragma once

#include <SFML/Graphics.hpp>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:

	sf::Sprite sprite;
	sf::Texture texture;

	//Thrust
	float fThrust = 0.00000025f;
	float sThrust = 0.000000005f;
	float rThrust = 0.00000001f;

	//Turning
	float turnSpeed = 0.1f;

	//Various movement variables
	float maxSpeed = 0.001f;

	//Constructors/Destructors
	Player(int x, int y);
	~Player();
	
	//Code to be executed once per game loop
	void update(int frameTime);

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