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

	//Code to be executed once per game loop
	virtual void update(int frameTime);

	//Draw entity to designated window
	virtual void draw(sf::RenderWindow* window);

	//Movement functions
	void thrLeft();
	void thrRight();
	void thrForward();
	void thrBack();

	Entity* getTar();

	double calcRotate(Entity * Ent);


private:

	//Holds current speed on current heading
	float heaSpeed;

	//Position
	float _x = 0, _y = 0;

	//Heading and thrust vectors
	sf::Vector2f heading;
	sf::Vector2f thrust;

	//Rotation variables
	double direction;
	//double curDirection;
	double tarDirection;
	double turn;
	double prevDirection;

};







#endif