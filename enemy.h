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
	float fThrust = 0.0000025f;
	float sThrust = 0.0000012f;
	float rThrust = 0.0000015f;
	float maxSpeed = 0.0001f;
	float turnSpeed = 0.00005f;

	//Entity Position
	virtual float getx();
	virtual float gety();

	//Entity Direction
	virtual double getDir();

	//Entity Heading
	virtual sf::Vector2f getHea();

	//Entity Thrust
	virtual sf::Vector2f getThr();

	//Entity Turn Speed
	virtual float getTurnSpeed();

	//Entity Max Speed
	virtual float getMaxSpeed();

	void setTar(Entity* target);
	Entity* getTar();

	//Code to be executed once per game loop
	virtual void update(int frameTime);

	//Draw entity to designated window
	virtual void draw(sf::RenderWindow* window);

private:

	//Heading and thrust vectors
	sf::Vector2f heading;
	sf::Vector2f thrust;

	//Movement variables
	double direction;
	float _x = 0, _y = 0;
	double curDirection;
	double tarDirection;
	double prevDirection;
	double turn;
	float getDirection;

	//Targeting variables
	Entity* target;
};

#endif