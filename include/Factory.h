//
//  Factory.h
//  lab7
//
//  Created by Андрей Журавлев on 16.04.2020.
//  Copyright © 2020 Андрей Журавлев. All rights reserved.
//

#ifndef Factory_h
#define Factory_h
#include "Ocean.h"
#include "Object.h"
#include "Cell.h"
#include "Coordinates.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"


#endif /* Factory_h */



class Factory {
	
	
public:
	static Object* createObject(ObjectTypes type, Cell* cell);
};
