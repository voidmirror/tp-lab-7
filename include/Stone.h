//
//  Stone.h
//  lab7
//
//  Created by Андрей Журавлев on 16.04.2020.
//  Copyright © 2020 Андрей Журавлев. All rights reserved.
//

#ifndef Stone_h
#define Stone_h
#include "Object.h"

class Stone: public Object {
	
public:
	
	Stone(Cell* cell) : Object(cell) {}
	
	bool live() { return true; }
	
	char getSymbol() { return STONE_CHAR; }
};


#endif /* Stone_h */
