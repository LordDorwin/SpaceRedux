//scripts.h
//header for scripts file

#include <SFML/System/Vector2.hpp>
#include "entity.h"
#pragma once

#ifndef SCRIPTS_H
#define SCRIPTS_H

namespace scr {
	//rotation of entity toward target
	double calcRotate(Entity* Ent);
	//calculation of heading for current frame
	sf::Vector2f calcHeading(Entity* Ent, int frameTime);
};

#endif
