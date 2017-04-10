//player.cpp
//Implementation file for player class

#include "player.h"


Player::Player(){

}

Player::~Player(){

}

void Player::setControl(Ally * nAlly){
	this->ally = nAlly;
}

float Player::getx(){
	return ally->getx();
}

float Player::gety()
{
	return ally->gety();
}

void Player::thrLeft(){
	ally->thrLeft();
}

void Player::thrRight(){
	ally->thrRight();
}

void Player::thrForward(){
	ally->thrForward();
}

void Player::thrBack(){
	ally->thrBack();
}


