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
	float fThrust = 0.00035;
	float sThrust = 0.0002;
	float rThrust = 0.0002;

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
	void rotate(double tarDirection);
private:
	
	float _x = 0, _y = 0, _dx = 0, _dy = 0;
	double direction;

};







#endif