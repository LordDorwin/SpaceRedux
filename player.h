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

	//Constructors/Destructors
	Player(float x, float y);
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
	
	float _x = 0, _y = 0, _dx = 0, _dy = 0, _playerSpeed = 0;
	double direction = 0;

};







#endif