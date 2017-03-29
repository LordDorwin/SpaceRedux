//group.cpp
//Implementation for group class

#include "group.h"

Group::Group() {

}

Group::~Group() {

}

void Group::add(Entity* Ent) {
	GrpList.push_front(Ent);
}

void Group::remove(Entity* Ent) {
	GrpList.remove(Ent);
}

void Group::update(int frameTime) {
	for (auto ci = GrpList.begin(); ci != GrpList.end(); ci++){
		(*ci)->update(frameTime);
	}
}

void Group::draw(sf::RenderWindow * window){
	for (auto ci = GrpList.begin(); ci != GrpList.end(); ci++) {
		(*ci)->draw(window);
	}
}
