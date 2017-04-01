//enemy.h
//Header file for enemy class

#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "entity.h"

class Enemy : public Entity{
public:

	//Constructors/Destructors
	Enemy();
	Enemy(int x, int y);
	~Enemy();

	sf::Sprite sprite;
	sf::Texture texture;

	//Movement variables
	float turnSpeed = 0.00003003f;

	virtual float getx();
	virtual float gety();

	void setTar(Entity* target);

	//Code to be executed once per game loop
	virtual void update(int frameTime);

	//Draw entity to designated window
	virtual void draw(sf::RenderWindow* window);

private:
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