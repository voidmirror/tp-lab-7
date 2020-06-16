//
//  Cell.cpp
//  lab7
//
//  Created by Андрей Журавлев on 21.04.2020.
//  Copyright © 2020 Андрей Журавлев. All rights reserved.
//

#include <stdio.h>
#include "Cell.h"


Cell* Cell::findEmptyCell() {
	return ocean->findEmptyCell(coord);
}

Cell* Cell::findPrey() {
	return ocean->findPrey(coord);
}

void Cell::setObject(Object *obj) {
	this->obj = obj;
	if (std::find(this->ocean->getOceanBegin(), this->ocean->getOceanEnd(), obj) == this->ocean->getOceanEnd() && obj != nullptr) {
		this->ocean->addObject(obj);
	}
}
