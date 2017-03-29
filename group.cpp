//group.cpp
//Implementation for group class

#include "group.h"

Group::Group(){
	
}

Group::~Group(){

}

void Group::grpAdd(Entity* Ent){
	GrpList.push_front(Ent);
}

void Group::grpRemove(Entity* Ent){
	GrpList.remove(Ent);
}
