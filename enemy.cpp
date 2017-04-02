//enemy.cpp
//Implementation of enemy class

#include "enemy.h"
#include "utility.h"
#include "globals.h"
#include "scripts.h"

Enemy::Enemy(){

}

Enemy::Enemy(int x, int y){
	_x = x;
	_y = y;

	texture.loadFromFile("Sprites/enemy_ship.png");
	texture.setSmooth(true);

	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.setOrigin(sf::Vector2f(22, 11.5));
}

Enemy::~Enemy(){

}

float Enemy::getx()
{
	return _x;
}

float Enemy::gety()
{
	return _y;
}

double Enemy::getDir()
{
	return prevDirection;
}

sf::Vector2f Enemy::getHea()
{
	return heading;
}

sf::Vector2f Enemy::getThr()
{
	return thrust;
}

float Enemy::getTurnSpeed()
{
	return turnSpeed;
}

float Enemy::getMaxSpeed()
{
	return maxSpeed;
}

void Enemy::setTar(Entity * target){
	this->target = target;
}

void Enemy::update(int frameTime){
	prevDirection = (double)(sprite.getRotation());
	//tarDirection = pointDirection((int)_x, (int)_y, mouse::x, mouse::y);
	turn = scr::calcRotate(this) * frameTime;
	direction = prevDirection + turn;
	sprite.setPosition(sf::Vector2f(_x, _y));
	sprite.rotate(turn);
	heading = scr::calcHeading(this, frameTime);
}

void Enemy::draw(sf::RenderWindow * window){
	window->draw(sprite);
}
