//
//  Factory.cpp
//  lab7
//
//  Created by Андрей Журавлев on 23.04.2020.
//  Copyright © 2020 Андрей Журавлев. All rights reserved.
//

#include <stdio.h>
#include "Factory.h"

Object* Factory::createObject(ObjectTypes type, Cell *cell) {
	switch (type) {
		case STONE:
			return new Stone(cell);
			break;
		case PREY:
			return new Prey(cell);
			break;
		case PREDATOR:
			return new Predator(cell);
			break;
			
		default:
			return nullptr;
			break;
	}
	return nullptr;
}
